// Back From Summer '19 P1: Winnie's Orphans

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
func main() {
	bytes, _ := ioutil.ReadAll(os.Stdin)
	_tk = strings.Fields(string(bytes))

	n, m := su(), su()
	mn := m + 1
	ind := -1
	for i := 0; i < n; i++ {
		count := 0
		for j := 0; j < m; j++ {
			a := su()
			if a == 1 || a == 10 {
				count++
			}
		}
		if count < mn {
			mn = count
			ind = i
		}
	}
	fmt.Println(ind + 1)
}
