let triangle_number n = n * (n + 1) / 2;;

let positive_root a b c =
  let f_a = float_of_int a in
  let f_b = float_of_int b in
  let f_c = float_of_int c in
  (-.f_b +. sqrt (f_b *. f_b -. 4. *. f_a *. f_c)) /. (2. *. f_a)
;;
let is_integer f_x =
  float_of_int (int_of_float f_x) = f_x
;;

let is_pentagonal x =
  (* rearrange the equation n(3n - 1) / 2 = x
    the number is pentagonal if the positive
    root is an integer *)

  (* rearranged to 3n^2 - n - 2x = 0 *)
  is_integer (positive_root 3 (-1) (-2 * x))
;;

let is_hexagonal x =
  (* same as before but different coefficients *)

  (* rearranged to 2n^2 - n - x = 0 *)
  is_integer (positive_root 2 (-1) (-x))
;;

let rec find_number num =
  let tri = triangle_number num in
  if is_pentagonal tri && is_hexagonal tri then tri
  else find_number (num + 1)
;;

print_endline (string_of_int (find_number 286));;