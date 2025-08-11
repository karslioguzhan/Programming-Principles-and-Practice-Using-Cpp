# Chapter 2: Hello, World!
1. What is the purpose of the "Hello World!" program!
    * It shows a very basic program which outputs the text Hello World and moves the cursor one line under. 
    It should show the learner the syntax etc.

2. Name the four parts of a function.
    * Return type
        * Show what the function should return
    * Name
        * The name of the function
    * Parameters
        * Are the input Parameters which the function needs to return
    * Function body
        * Are the set of instruction the function calls

3. Name a function that must appear in every C++ program.
    * The main function must appear in every C++ program. Because it is the entry point of the program.

4. In the "Hello World!" program, what is the purpose of the line return 0;?
    * The return 0 indicates that the program runs successfully to the end.

5. What is the purpose of the compiler?
    * The compiler translates the C++ code written by human to computer readable code, which is called machine code.

6. What is the purpose of the #include directive? 
    * The includes are the codes which is written from someone else that we are using. Like stdio (standard input output)

7. What does a .h suffix at the end of a file name signify in C++?
    * The .h shows that this is a header file.

8. What does the linker do for your program?
    * The linker links the object codes from the includes and the written ones into the executuble.

9. What is the difference between a source file and an object file?
    * The source file is file which is coded by a human and the object file is the translation of it to machine code.

10. What is an IDE and what does it do for you?
    * The IDE (Integrated Developement Environment) is a tool for writing code with features like code highlighting etc. 
    * The IDE also do the compiling and linking job for the user.

11. If you understand everything in the textbook, why is it necessary to practice?
    * Like every skill based activity programming need practice to refine and learn the skill. 
    * It is necessary to learn from errors, which only possible if someone codes for its own.

# Chapter 3: Objects, Types, and Values
1. What is meant by the term prompt?
    * A request for example inserting a char or number into command prompt

2. Which operator do you use to read into a variable?
    * ">>"

3. If you want the user to input an integer value into your program for a variable named number, what are two lines of code you could write to ask the user to do it and to input the value into your program?
    * std::cout << "Enter a interger: "
    * std::cin >> number;

4. What is \n called and what purpose does it serve?
    * This is a linebreak in C++ Strings.

5. What terminates input into a string?
    * A white space

6. What terminates input into an integer?
    * A character which is not an digit.

7. How would you write
    * std::cout << "Hello, " << first_name << "!\n";

8. What is a object?
    * A Object is some memory that holds a value of a given type.

9. What is a literal?
     * Notation for values of bool, character types, integer types, or floating-point type. Literals represent values of various types. For example, the literal 12 represents the integer value “twelve”, “Morning” represents the character string value Morning, and true represents the Boolean value true.

10. What kind of of literals are there?
    * Decimal
    * Octac where the digits starts with 0 example: 012
    * Hexadecimal where the digits starts with 0x/0X example: 0x12
    * Binary where the bits starts with 0b/0B example 0b0011

11. What is a variable?
    * A variable is a named object with type.

12. What are typical sizes for a char, an int, and a double?
    *  char = 1 Byte
    *  int = 4 Byte
    *  double = 8 Byte

13. What measures do we use for the size of small entities in memory, such as ints and strings?
    * Byte

14. What is the difference between = and ==?
    * The = is the assignment operator which assings the righthand side with the variable on the left (lefthand side).
    * == is a equality operator which checks if both sides are identical

15. What is a definition?
    * Is a declartion that sets aside memory for an object. A Definition is when a variable name is declared and a value is initialized. 

16. What is an initialization and how does it differ from an assignment?
    *  A initialization creates an object with an value in memory. A assignment assigns a value to a variable. 
    *  Initialization (giving a variable its initial value)
    *  Assignment (giving a variable a new value)

17. What is string concatenation and how do you make it work in C++?
    * A string concatenation is adding two strings together. For C++ strings you can use the + operator.

18. Which of the following are legal names in C++? If a name is not legal, why not?
    *  2_For_1_special --> A variable name cannot start with a number
    *  latest things --> whitespaces are illegal for variable names
    *  the_$12_method --> non ASCII characters are illegal
    *  correct? --> non ASCII characters are illegal

19. Give five examples of legal names that you shouldn’t use because they are likely to cause confusion.
    * Giving to short variable names like x. You shouldn’t also not use string, int etc. because it can be confused with the standard libary.

20. What are some good rules for choosing name?
    * Your variable name should be understandable without to become too long. Also stick with your nameing style. Do not use All Caps because it is used for makros.

21. What is type safety and why is it important?
    * Every object is given a type when it is defined. A program — or a part of a program — is type-safe when objects are used only according to the rules for their type. Unfortunately, there are ways of doing operations that are not type-safe. For example, using a variable before it has been initialized is not considered type-safe.

22. Why can conversion from double to int be a bad thing?
    * Because double contains more information than int a conversion can loss data. For example: 12.1 --> 12

23. Define a rule to help decide if a conversion from one type to another is safe or unsafe.
    *  A conversion should be unsafe when the target type have less memory than the source.


# Chapter 4: Computation
1. What is a computation?
    * By computation we understand that we produce some kind of output for given input. 
    We use a function like "square" to produce a result (output) with arguments (input).

2. What do we mean by inputs and outputs to a computation? Give examples.
    * A input is a argument that is given to program or function, which is used for the computation. 
    A output is the result of an computation which is provided after a program or functions runs. 
    Like if use the function square(2) the "2" is the input and the result will be "4" (output).

3. What are the three requirements a programmer should keep in mind when expressing computations?
    * The three requirements for correct computation are:
        * correctness
        * simplicity
        * efficiency

4. What does an expression do?
    * A expression computes a value from a number of operands. Simple expressions are literal values like 10 or "Norah".
    * A variable represents a expression to like: int length = 20;

5. What is the difference between a statement and an expression, as described in this chapter?
    * A expression computes a value from a set of operands using operations. A statement can produce many output and can read inputs.
    * Also a statement can be do expressions many times. A example statement:
        * a = b;
            * "=" is a an operators --> in this case a assignment operator
            * "a = b" is an expression --> assign b to a
            * And with an ";" this becomes an statement.
    * The are two kinds of statements:
        * expression statement
        * declarations

6. What is an lvalue? List the operators that require an lvalue. Why do these operators, and not the others, require an lvalue?
    * An lvalue is for short a value that appears on the left side of an operand and mostly the one value that will be modified. 
    * The complement to lvalue is rvalue, that is, an expression that identifies something that may not be modified or have its address taken, such as a value returned from a function (&f(x) is an error because f(x) is an rvalue).
    * Operators that require an lvalue for example are:
        * assignment like a = b;
        * pre/post increment ++a; a++;

7. What is a constant expression?
    * A constant expression are expressions that we don't want to change in our code. For example a pi could be an constant expression.
    * After initialization of an constant expression like "constexpr double pi{3.14159}" you cannot change the value.

8. What is a literal?
    * Literals represent values of various types. For example, the literal 12 represents the integer value “twelve”, 
    * "Morning" represents the character string value Morning, and true represents the Boolean value true.

9. What is a symbolic constant and why do we use them?
    * C++ offers the notion of a symbolic constant, that is, a named object to which you can’t give a new value after it has been initialized. For example:
        * constexpr double pi = 3.14159;

10. What is a magic constant? Give examples.
    * Non obvious literals in code considered to be magic constants, because it is not clear what this value stands for.
    * Like if you want to compute:
        * meter = lengthInch * 0.0254; --> In this context it is clear what the number does but for other cases this magic numbers are irritating.

11. What are some operators that we can use for integers and floating-point values?
    * We can use following operators for float and integers:
        * "+" --> Addition
        * "-" --> Subtraction
        * ">=" greater than

12. What operators can be used on integers but not on floating-point numbers?
    * The modulo operator "%" which gives the remainder as a result can only be used for integers.

13. What are some operators that can be used for strings?
    * For strings we can use addition "+" , assignment "=" or check for equality "==".

14. When would a programmer prefer a switch-statement to an if-statement?
    * The switch and if statements are selections. You should prefer switch statements if you have many possible selections. With if-statemens you have to nest many if else if etc. Because of that switch statements are more clear.

15. What are some common problems with switch-statements?
    * The Syntax of an switch statement is slightly archaic. 
    * You can only use chars, enumerations or integers
    * The case labels must be constant expression
    * You have to end each case with an break.

16. What is the function of each part of the header line in a for-loop, and in what sequence are they executed?
    * A for loop is like an while statement, but you have the sequence control inside the header. 
    * For example:
        ```
        for (int numIteration{0}; numIteration < 10; ++numIteration)
        {
            std::cout << numIteration << std::endl;
        }
        ```
        * The header have the initialization of an integer, after that you have the condition to finish the loop and lastly with the third argument you decide what you do after each iteration. In this example we increment the value of numIteration with one. (initialization, condition, increment)

17. When should the for-loop be used and when should the while-loop be used?
    * If you have to modify the loop variable inside a iteration you should consider using a while loop. For loops are great when you know how many times you want to iterate.

18. How do you print the numeric value of a char?
    * You can use typecasting --> int('a');
    * You can use static cast --> static_cast<int>('a');

19. Describe what the line char foo(int x) means in a function definition.
    * This lines means we use an integer x for the function foo as an input and after a computation we get an char as result.

20. When should you define a separate function for part of a program? List reasons.
    * You want to use a sequence of computation more than once
    * More readable code
    * Separation of the computation logically
    * Easier testing

21. What can you do to an int that you cannot do to a string?
    * We can use the modulo operator for an integer.

22. What can you do to a string that you cannot do to an int?
    * We can use member functions of string which the type int doesn't have.

23. What is the index of the third element of a vector?
    * The index of the third element is "2" because we start counting by 0.

24. How do you write a for-loop that prints every element of a vector?
    * We used range-for-loop (sometimes called foreach loop) to iterate through a vector. In this example it would be look like this:
    ```
    std::vector<int> test {1,2,3};
    for (int numTest : test)
    {
        std::cout << numTest << std::endl;
    }
    ```

25. What does vector<char> alphabet(26); do?
    * This initializes a vector that can hold 26 elements of type char which are initialized to '\0', the null/empty char.

26. Describe what push_back() does to a vector.
    * The push_back() member-function puts an new value in the end of the vector.

27. What do vector’s member functions begin(), end(), and size() do?
    * The member functions begin() and end() of a vector return iterators, begin and end; they identify the beginning and the end of the sequence. An STL sequence is what is usually called “half-open”; that is, the element identified by begin is part of the sequence, but the end iterator points one beyond the end of the sequence. The usual mathematical notation for such sequences (ranges) is [begin:end). An iterator is an object that identifies an element of a sequence. The member function size() returns the number of elements stored in a vector. The call v.size() gives the number of elements of the vector called v. In general, v.size() gives us the ability to access elements of a vector without accidentally referring to an element outside the vector’s range. The range for a vector v is [0:v.size()). That’s the mathematical notation for a half-open sequence of elements. The first element of v is v[0] and the last v[v.size()–1]. If v.size==0, v has no elements, that is, v is an empty vector. This notion of half-open sequences is used throughout C++ and the C++ standard library (§17.3, §20.3).

28. What makes vector so popular/useful?
    * A vector is similar to an array in C and other languages. However, you need not specify the size (length) of a vector in advance, and you can add as many elements as you like. The C++ standard vector has other useful properties.

29. How do you sort the elements of a vector?
    * A vector is similar to an array in C and other languages. However, you need not specify the size (length) of a vector in advance, and you can add as many elements as you like. The C++ standard vector has other useful properties.

# Chapter 5: Errors
1. Name four major types of errors and briefly define each one.
    * Compile-time errors
        * Errors found from the compiler like syntax or type errors
    * Link-time errors
        * Errors found by the linker when it is trying to link the object files
    * Run-time errors
        * Errors found by checks in a running program. It can be detected from the computer, a library or by the user code.
    * Logic errors
        * Errors found by the programmer looking for the causes of erroneous results.

2. What kinds of errors can we ignore in student programs?
    *  Errors like misbehaving hardware or from system software are not the scope of this book.

3. What guarantees should every completed project offer?
    *  Should produce the desired results for all legal inputs.
    *  Should give reasonable error messages for all illegal inputs.
    *  Need not worry about misbehaving hardware.
    *  Need not worry about misbehaving system software.
    *  Is allowed to terminate after an error.

4. List three approaches we can take to eliminate errors in programs and produce acceptable software.
    * Organize software to minimize errors.
    * Eliminate most of the errors we made through debugging and testing.
    * Make sure the remaining errors are not serious.

5. Why do we hate debugging?
    * Because debugging i likely the most tedious and time-wasting aspects of programming.

6. What is a syntax error? Give five examples.
    * Is a compile time error and the compiler reject this statements because is not according to the C++ grammar.
    * Examples
        * Int test; --> it should be int
        * int test  --> missing semicolon
        * function("hallo) --> quote not terminated
        * int test, --> Statement not terminated
        * vector test; --> Vector not right defined

7. What is a type error? Give five examples.
    * Is a compile time error where the compiler reports that the types between for your variables, functions etc. mismatches.
    * Examples
        * function(int, int) -> function("hallo", 5); --> False input
        * function(int, int) -> function(5); --> Missing input
        * function(int, int) -> Function(5); --> Undeclared function
        * function(int, int) -> function(5, 6, 6); --> too many arguments
        * function(int, int) -> function(); --> Missing function arguments

8. What is a linker error? Give three examples.
    * A linker error is when the separate compiled parts (translation units) cannot be correctly linked from the linker.
    * Examples
        * Calling a function where the function prototype exists but not the definition.
        * Calling a function with the same name but different types.
        * Calling a function with same name but different number of arguments.

9. What is a logic error? Give three examples.
    * A logic errors can be found when all linker and compiler errors were fixed and the program runs.
    * Typically the program generates not the desired output or returns a false output.
    * Examples  
        * For example when calculating an area and the input is negative --> negative length didn't exists
        * A calculation return a value that is not physically correct --> faster than the speed of light
        * When values gets calculated but the implicit conversion is false like if you want a double but inserted a integer division.

10. List four potential sources of program errors discussed in the text.
    * Compiler errors
    * Linker errors
    * Run time errors
    * Logic errors

11. How do you know if a result is plausible? What techniques do you have to answer such questions?
    * For checking the plausibility of an result you need experience and system understanding. Some errors are easy to determine like negative areas and other are not trivial like is a hour from a city to a city legit?
    * Techniques
        * Estimations
            * We can use easy calculations to check if the results are in the right range.
            * We can use online resources for validating results

12. Compare and contrast having the caller of a function handle a run-time error vs. the called function's handling the run-time error.
    * Caller checks inputs
        * When the caller checks for legal inputs the user/function that calls the function has to be check.
        * This approach used if you cannot change or see the function which you try to call.
        * The problem with that approach is, that every time you want to call the function you have to check it before the call
    * Callee checks inputs 
        * This approach tests the arguments if they are legit inside the function self.
        * Beneficial of this approach is that we only include the test logic once in the function self

13. Why is using exceptions a better idea than returning an "error value"?
    * The use of exceptions is good because with that you have to catch the error. If the error can't be catched the program terminates unlike when you return a error value.

14. How do you test if an input operation succeeded?
    * You can check if an error is thrown. First you can check if the pre-conditions are met and after executing the body you can check the result with the post-conditions.

15. Describe the process of how exceptions are thrown and caught.
    * The basic idea is, that if a function finds an error it cannot handle it does not return normally. Instead it throws an exception. 

16. Why, with a vector called v, is v[v.size()] a range error? What would be the result of calling this?
    * Because the v.size() method return the number of elements but in c++ the addressing starts with 0 and this call will be outside the boundary.
    * Depending on the compiler an error like this should appear: "terminate called after throwing an instance of 'std::out_of_range'"

17. Define pre-condition and Post-condition; give an example (that is not the area() function from this chapter) , preferably a computation that requires a loop.
    * For example we try to check if input is zero by a division and in the postcondition we check if we exceed the range of the vector
    * Example:
    ```
    int main()
    {
        std::vector<int> test(5);
        int input;
        std::cin>> input;
        // Precondition
        try{
            if(input==0)
            {
                throw std::logic_error("Cannot divide by zero!");
            }
        }
        catch(...)
        {
            std::cerr << "Input was 0!\n";
        }
        for(int i=0; i<=test.size(); ++i)
        {
            try{
                // Postcondition
                std::cout << test.at(i)/input << "\n";
            }
            catch(...)
            {
                std::cerr << "Failed\n";
            }
        }
        return 0;
    }
    ```
18. When would you not test a pre-condition?
    * Nobody would give bad arguments
    * It would slow down my code
    * It's too complicated to check

19. When would you not test a post-condition?
    * Probably too complicated to check and performance issues

20. What are the steps in debugging a program?
    * Debugging can be split generally into three steps
        * Get the program to compile
        * Get the program to Link
        * Get the program to do what it is supposed to do.

21. Why does commenting help when debugging?
    * Because when you are commenting good the user should know what the function/program should do, which arguments it should get and what the possible legit answer was.
    * In addition to that, you can write what you want to achieve. It shouldn't be the code just in english vocabulary!

22. How does testing differ from debugging?
    * The testing is performed after you build your program with a set of selected inputs and their outputs.
    * This so called testcases tests the program for legit responses