open Utils;
let input =
  getLines(~splitBy=',', "./input.txt")
  ->Belt.List.keepMap(x =>
      try(Some(int_of_string(x))) {
      | _ => None
      }
    );

let intCodes = input->Belt.List.toArray;

let op = (operation, nextCodeIdx, intCodes) => {
  intCodes[intCodes[nextCodeIdx + 3]] =
    operation(
      intCodes[intCodes[nextCodeIdx + 1]],
      intCodes[intCodes[nextCodeIdx + 2]],
    );
};

let rec process = (nextCodeIdx, intCodes) =>
  switch (intCodes[nextCodeIdx]) {
  | 1 =>
    op((+), nextCodeIdx, intCodes);
    process(nextCodeIdx + 4, intCodes);
  | 2 =>
    op(( * ), nextCodeIdx, intCodes);
    process(nextCodeIdx + 4, intCodes);
  | _ => intCodes
  };
intCodes[1] = 12;
intCodes[2] = 2;
let part1 = process(0, intCodes)[0];
Js.log(part1);

let part2 = {
  let values = Belt.List.makeBy(100, i => i + 1);
  let pairs =
    values
    ->Belt.List.map(x => values->Belt.List.map(y => (x, y)))
    ->Belt.List.flatten;

  let (noun, verb) =
    pairs
    ->Belt.List.keepMap(inputs => {
        let (noun, verb) = inputs;
        let intCodes = input->Belt.List.toArray;

        intCodes[1] = noun;
        intCodes[2] = verb;

        process(0, intCodes)[0] === 19690720 ? Some(inputs) : None;
      })
    ->Belt.List.getExn(0);

  100 * noun + verb;
};

Js.log(part2);