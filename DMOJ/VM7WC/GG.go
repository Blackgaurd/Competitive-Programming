// VM7WC '16 #2 Silver - GG

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

	g := _tk[_iop]
	_iop++

	psa := make([]int, len(g)+1)
	for i, c := range g {
		if c == 'G' {
			psa[i+1]++
		}
		psa[i+1] += psa[i]
	}

	q := su()
	for q > 0 {
		q--
		a, b := su(), su()
		fmt.Println(psa[b+1] - psa[a])
	}
}
