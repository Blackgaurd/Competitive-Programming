// DMOPC '14 Contest 8 P1 - Flare

package main

import "fmt"

func main() {
	const g = -9.8
	var v int
	fmt.Scanf("%d", &v)
	var t float32 = float32(v) * -2 / g
	fmt.Println(t)
}
