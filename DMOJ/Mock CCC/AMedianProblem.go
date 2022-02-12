// Mock CCC '18 Contest 3 J4/S2 - A Median Problem

package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"sort"
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
func main() {
	bytes, _ := ioutil.ReadAll(os.Stdin)
	_tk = strings.Fields(string(bytes))

	n := su()
	full := make([]int, 0, n)
	for i := 0; i < n; i++ {
		cur := make([]int, 0, n)
		for j := 0; j < n; j++ {
			cur = append(cur, su())
		}
		sort.Ints(cur)
		full = append(full, cur[n/2])
	}
	sort.Ints(full)
	fmt.Println(full[n/2])
}
