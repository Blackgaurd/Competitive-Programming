let square_digits x =
  let square x = x * x in
  let rec loop num acc =
    match num with
    | 0 -> acc
    | _ -> loop (num / 10) (acc + square (num mod 10))
  in
    loop x 0
;;

let rec ends_in_89 x =
  match x with
  | 1 -> false
  | 89 -> true
  | x -> ends_in_89 (square_digits x)
;;

let cnt = ref 0;;
for i = 1 to 10000000 do
  if ends_in_89 i then cnt := !cnt + 1
  done;;

print_endline (string_of_int !cnt);;