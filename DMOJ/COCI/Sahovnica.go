// COCI '12 Contest 3 #1 Sahovnica

package main

import (
	"fmt"
)

func main() {
	var r, c, a, b int
	fmt.Scanf("%d %d\n%d %d", &r, &c, &a, &b)
	for i := 0; i < r; i++ {
		for x := 0; x < a; x++ {
			for j := 0; j < c; j++ {
				var ch byte
				if (i+j)%2 == 0 {
					ch = 'X'
				} else {
					ch = '.'
				}
				for y := 0; y < b; y++ {
					fmt.Printf("%c", ch)
				}
			}
			fmt.Println()
		}
	}
}
