# Word Alignment

I did a simple problem for an interview for a C++ heavy new grad dev position and received this problem. I post a
possible solution here. 

## Problem

When given some number of separate roman letter words, contained in Textboxes, how do you align those boxes\
 such that the baseline lines up?

Write a function that returns a correct minimal Y-offset for each Textbox given print it with the provided 
`Textprint` function. You are also provided a function, `test`, that will construct randomized tests
and accept a `solution` function with the same parameters as my provided solution.

Your output without adjustment will print vertically and look like this

```
Hello WordAlignment!

0|0000
0|0000
0|0000
0|0000
0|0000

|000000
|000000
|000000
|000000
|000000

000|
000|
000|
000|
```

...and like this after

```
Hello WordAlignment!

--0|0000
--0|0000
--0|0000
--0|0000
--0|0000

---|000000
---|000000
---|000000
---|000000
---|000000

000|
000|
000|
000|
```

Can you make the bars match for the randomized test cases in `test`?