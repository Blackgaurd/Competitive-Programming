// COCI '12 Contest 3 #1 Sahovnica

package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

func main() {
	bytes, _ := ioutil.ReadAll(os.Stdin)
	fields := strings.Fields(string(bytes))
	r, _ := strconv.Atoi(fields[0])
	c, _ := strconv.Atoi(fields[1])
	a, _ := strconv.Atoi(fields[2])
	b, _ := strconv.Atoi(fields[3])
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
