// SAC '22 Code Challenge 4 P3 - Obligatory Math Problem

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
	arr := make([]int, n, n)
	for i := 0; i < n; i++ {
		arr[i] = su()
	}
	sort.Ints(arr)
	fmt.Println(arr[n/2])
}
