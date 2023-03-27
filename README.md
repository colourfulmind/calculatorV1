# Calculator v1.0

The program is implemented in C language of C11 standard using gcc compiler. <br>
The program is built with Makefile which contains standard set of targets for GNU-programs: all, install, uninstall, clean, dvi, dist, test, gcov_report.<br>
GUI is implemented with Qt tools.

## Classic calculator

Both integers and real numbers with a dot can be input into the program. 
The calculation starts after you complete entering the calculating expression and press the `=` symbol.

- Arithmetic expressions support the following arithmetic operations and mathematical functions:
    - **Arithmetic operators**:

      | Operator name | Visualisation |
      |---------------| ------ |
      | Brackets | (a + b)       |
      | Addition | a + b         |
      | Subtraction | a - b         |
      | Multiplication | a * b         |
      | Division | a / b         |
      | Power | a ^ b         |
      | Modulus | a mod b       |
      | Unary plus | +a            |
      | Unary minus | -a            |

    - **Functions**:
  
      | Function description | Function |
      | ------ | ------ |
      | Computes cosine | cos(x) |
      | Computes sine | sin(x) |
      | Computes tangent | tan(x) |
      | Computes arc cosine | acos(x) |
      | Computes arc sine | asin(x) |
      | Computes arc tangent | atan(x) |
      | Computes square root | sqrt(x) |
      | Computes natural logarithm | ln(x) |
      | Computes common logarithm | log(x) |
    
## Credit calculator

There is a special mode "credit calculator":
- Input: total credit amount, term, interest rate, type (annuity, differentiated)
- Output: monthly payment, overpayment on credit, total payment


## Deposit calculator

Another special mode "deposit profitability calculator":
- Input: deposit amount, deposit term, interest rate, tax rate, periodicity of payments, capitalization of interest, replenishments list, partial withdrawals list
- Output: accrued interest, tax amount, deposit amount by the end of the term
