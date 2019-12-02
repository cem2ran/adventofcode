let getLines = (~splitBy='\n', path) =>
  path
  |> Node.Fs.readFileAsUtf8Sync
  |> String.split_on_char(splitBy)
  |> Belt.List.keep(_, s => String.length(s) > 0);

let (>>) = (f, g, x) => g(f(x));

let sumListBy = (input, f) =>
  input->Belt.List.map(int_of_string >> f)->Belt.List.reduce(0, (+));