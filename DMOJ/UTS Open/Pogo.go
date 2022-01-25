// UTS Open '15 #3 - Pogo

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

const MM int = 1e5 + 3
const MOD int = 1e9 + 7

var ma, mb, mc1, mc2, md, mf [MM]int

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
func f(n int) int {
	if n <= 1 {
		return max(n, 0)
	}
	if mf[n] == -1 {
		mf[n] = (f(n-1) + f(n-3)) % MOD
	}
	return mf[n]
}
func a(n int) int {
	if n <= 1 {
		return max(n, 0)
	}
	if ma[n] == -1 {
		ma[n] = (a(n-1) + b(n-2)) % MOD
		ma[n] = (ma[n] + c1(n-3)) % MOD
	}
	return ma[n]
}
func b(n int) int {
	if n <= 0 {
		return 0
	}
	if mb[n] == -1 {
		mb[n] = (a(n-2) + c2(n-3)) % MOD
		mb[n] = (mb[n] + d(n-1)) % MOD
		mb[n] = (mb[n] + d(n-3)) % MOD
	}
	return mb[n]
}
func c1(n int) int {
	if n <= 0 {
		return 0
	}
	if mc1[n] == -1 {
		mc1[n] = (a(n-2) + c2(n)) % MOD
	}
	return mc1[n]
}
func c2(n int) int {
	if n <= 0 {
		return 0
	}
	if mc2[n] == -1 {
		mc2[n] = (a(n-1) + a(n-2)) % MOD
		mc2[n] = (mc2[n] + c2(n-3)) % MOD
		mc2[n] = (mc2[n] + d(n-1)) % MOD
		mc2[n] = (mc2[n] + d(n-3)) % MOD
	}
	return mc2[n]
}
func d(n int) int {
	if n <= 0 {
		return 0
	}
	if md[n] == -1 {
		md[n] = (a(n) + b(n-1)) % MOD
	}
	return md[n]
}
func main() {
	bytes, _ := ioutil.ReadAll(os.Stdin)
	_tk = strings.Fields(string(bytes))

	n, m := su(), su()
	for i := 0; i <= n; i++ {
		mf[i] = -1
		ma[i] = -1
		mb[i] = -1
		mc1[i] = -1
		mc2[i] = -1
		md[i] = -1
	}
	if m == 1 {
		fmt.Println(1)
	} else if m == 2 {
		fmt.Println(f(n))
	} else {
		fmt.Println(a(n))
	}
}
