// CCC '97 S2 - Nasty Numbers

package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

var _tk []string
var _iop int = 0

func su() int {
	r, _ := strconv.Atoi(_tk[_iop])
	_iop++
	return r
}
func check(x int) bool {
	var sums, diff []int
	for i := 1; i*i <= x; i++ {
		if x%i == 0 {
			sums = append(sums, i+x/i)
			diff = append(diff, x/i-i)
		}
	}
	for _, s := range sums {
		for _, d := range diff {
			if s == d {
				return true
			}
		}
	}
	return false
}
func main() {
	bytes, _ := ioutil.ReadAll(os.Stdin)
	_tk = strings.Fields(string(bytes))

	n := su()
	for n > 0 {
		a := su()
		var ans string = ""
		if !check(a) {
			ans = " not"
		}
		fmt.Printf("%d is%s nasty\n", a, ans)
		n--
	}
}
