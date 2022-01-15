// DMOPC '14 Contest 2 P1 - Logging Log

package main

import "fmt"

func main() {
	var d, t int
	fmt.Scanf("%d", &d)
	for i := 1; i <= d; i++ {
		fmt.Scanf("%d", &t)
		sum := 0
		var a int
		for j := 0; j < t; j++ {
			fmt.Scanf("%d", &a)
			sum += a
		}
		if sum == 0 {
			fmt.Println("Weekend")
		} else {
			fmt.Printf("Day %d: %d\n", i, sum)
		}
	}
}
