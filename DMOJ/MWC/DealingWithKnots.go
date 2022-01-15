// MWC '15 #4 P4: Dealing with Knots

package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

var p [1003]int

func flead(x int) int {
	if p[x] != x {
		p[x] = flead(p[x])
	}
	return p[x]
}
func main() {
	bytes, _ := ioutil.ReadAll(os.Stdin)
	tk := strings.Fields(string(bytes))

	ptr := 0
	n, _ := strconv.Atoi(tk[ptr])
	ptr++
	for i := 1; i <= 1000; i++ {
		p[i] = i
	}
	for i := 1; i <= n; i++ {
		a, _ := strconv.Atoi(tk[ptr])
		b, _ := strconv.Atoi(tk[ptr+1])
		ptr += 2
		fa, fb := flead(a), flead(b)
		if fa != fb {
			p[fa] = fb
		}
	}
	for i := 1; i <= n; i++ {
		flead(i)
	}
	a, _ := strconv.Atoi(tk[ptr])
	b, _ := strconv.Atoi(tk[ptr+1])
	if flead(a) == flead(b) {
		fmt.Println("Tangled")
	} else {
		fmt.Println("Not Tangled")
	}
}
