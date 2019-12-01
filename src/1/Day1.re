open Utils;
let input = getLines("./input.txt");

// Integer division does rounding.
let fuelPerMass = mass => mass / 3 - 2;

let part1 = input->sumListBy(fuelPerMass);
Js.log(part1);

let rec addFuelOfFuel = fuel => {
  let fuelOfFuel = fuelPerMass(fuel);
  fuelOfFuel > 0 ? fuel + addFuelOfFuel(fuelOfFuel) : fuel;
};

let part2 = input->sumListBy(mass => mass |> fuelPerMass |> addFuelOfFuel);
Js.log(part2);