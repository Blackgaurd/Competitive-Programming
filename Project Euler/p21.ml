let sum_divisors n =
  let rec loop i acc =
    if i >= n then acc
    else if n mod i = 0 then loop (i + 1) (acc + i)
    else loop (i + 1) acc
  in
    loop 1 0
;;

let fast_sum_divisors n =
  let limit = int_of_float (sqrt (float_of_int n)) in
  let rec loop i acc =
    if i > limit then acc
    else if n mod i = 0 then
      let j = n / i in
      if i = j then loop (i + 1) (acc + i)
      else loop (i + 1) (acc + i + j)
    else loop (i + 1) acc
  in
    loop 1 0 - n
;;

let sum_amicable_nums n =
  let is_amicable a =
    let b = fast_sum_divisors a in
    a <> b && fast_sum_divisors b = a
  in
  let rec loop i acc =
    if i >= n then acc
    else if is_amicable i then loop (i + 1) (acc + i)
    else loop (i + 1) acc
  in
    loop 1 0
;;

let n = 10000;;
print_endline (string_of_int (sum_amicable_nums n));;