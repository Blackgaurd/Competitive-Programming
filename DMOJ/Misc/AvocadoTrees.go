// Avocado Trees!

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

var psa [1e6 + 3]int
var ans int = 0

func main() {
	bytes, _ := ioutil.ReadAll(os.Stdin)
	_tk = strings.Fields(string(bytes))

	n, q, h := su(), su(), su()
	for i := 1; i <= n; i++ {
		a, b := su(), su()
		psa[i] = psa[i-1]
		if a <= h {
			psa[i] += b
		}
	}
	for q > 0 {
		q--
		a, b := su(), su()
		if psa[b]-psa[a-1] > ans {
			ans = psa[b] - psa[a-1]
		}
	}
	fmt.Println(ans)
}
