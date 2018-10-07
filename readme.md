# Introduction

This projet aims to build a small library to construct and exploit Regex.

# Features

This library allows to use basic regex syntax :

 - Recognize text
 - Using set format like [a-zA-z_]
 - Quantifiers
	- \*
	- ?
	- \+
	- a{0,5}
	- Lazy quantifier using '?' after any others quantifiers
- Special caracter :
	- . everything except \n and \r
	- \t \n \r
	- \b \B for word and non word
	- \d \D for number and non number
	- \w \W for whitespace and non whitespace

# ToDos

- [x] Caracter support
- [x] Quantifier support
- [x] Set support
- [x] Special caracter support
- [ ] Anchor support
- [ ] Class for managing match and sub-match
- [ ] Separate Engine in two class, one for building regex, and one for containing them
- [ ] Group/non capturing group and Or '|'
- [ ] positive and negative lookahead