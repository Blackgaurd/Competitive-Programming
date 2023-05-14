(* generate a list of all numbers that are divisible
   by 3 or 5 between numbers a and b *)

let is_valid x =
  x mod 5 = 0 || x mod 3 =  0
;;

let rec gen a b =
  if a > b then []
  else if is_valid a then
    a :: gen (a + 1) b
  else gen (a + 1) b
;;

let gen_from_1 = gen 1;;

let rec sum arr =
  match arr with
  | [] -> 0
  | h :: t -> h + sum t
;;

let n = 1000 - 1;;
let nums = gen_from_1 n;;
let ttl = sum nums;;
print_int ttl;;
