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

# Chapter 6: Writing a program
1. What do we mean by "Programming is understanding"?
    * The statement "Programming is understating" tells us, that solving a problem without understand it properly could lead to false results and not useful programs

2. The chapter details the creation of a calculator program. Write a short analysis of the calculator should be able to do.
    * The program should do basic arithmetic like addition, subtraction, multiplication and division. 
    * It should respect braces and the rule which parts of an equation should be calculated first. etc. * over + 

3. How do yoe break a problem up into smaller manageable parts?
    * Look for tools and libraries that do specific task for your issue. It's not a good idea to reinvent a wheel for each program your write.
    * Look for parts of solution that can be separately described. For example:
        * User interaction
        * Calculation
        * Parsing

4. Why is creating a small, limited version of a program a good idea?
    * Creating a small prototype is useful because of:
        * To make problems of our understating, tools and ideas visible
        * To show definition lack in the problem description
        * To test small parts before having to test everything at once with is dependencies

5. Why is feature creep a bad idea?
    * Because we should consider the following trade of
        * Can we complete the project?
        * Do we have all skills, time and skill for more advanced solutions?
        * Should we consider problems we don't want to solve?

6. What are the three main phases of software development?
    * Analysis
        * Understanding the problem and writing down a set of requirements
    * Design
        * Creating a overall structure of the program to show which parts does which job and their interactions
    * Implementation
        * Writing, debugging and testing the code

7. What is a "use case"?
    * How a system/program can be used to achieve a specific goal or task.

8. What is the purpose of testing?
    * The purpose of testing is to test if the program behave as we intended 
    * Are the results as we expected
    * Do we consider all or most common "wrong" inputs and interactions
    * Is the program fast enough for its purpose

9. According to the outline in the chapter, describe the difference between a Term, an Expression, a Number and Primary.
    * Expression
        * Combination of operators, names and values
        * Is the "top rule" and must be Term
    * Term
        * A Term must be Primary or a term
        * It decides which action should be performed or is the value of the action
    * Primary
        * A primary is a number or an expression and will be used for the calculation
    * Number
        * Is the representing of the data 

10. In the chapter, an input was broken down into its component, Terms, Expressions, Primarys, and Numbers. Do this for (17+4)/(5-1).
    * ("(") = "(" Expression --> Primary --> Term --> Expression
        * (17) = Number --> Primary --> Term --> Expression
            * (+) = Expression
        * (4) = Number --> Primary --> Term --> Expression
    * (")") = ")" Expression --> Primary --> Term --> Expression
    * (/)
    * ("(") = "(" Expression --> Primary --> Term --> Expression
        * (5) = Number --> Primary --> Term --> Expression
            * (-) = Expression
        * (1) = Number --> Primary --> Term --> Expression
    * (")")  = ")" Expression --> Primary --> Term --> Expression

11. Why does the program not have a function called number()?
    * Because depending on the "input" an expression can be number and with this attempt it is easier to use grammar rules.

12. What is a token?
    * A token is a sequence of characters that represents something we consider a unit such as a number or operators

13. What is a grammar? A grammar rule?
    * A grammar defines the syntax of our input.
    * A grammar rules defines how our program interpret this syntax

14. What is a class? What do we use classes for?
    * A class can be considered like an user defined type
    * A class have members which representing values and methods which perform actions 
    * We use classes for splitting our problems into smaller parts and every "class" deals with its specials responsibility

15. How can we provide a default value for a member of a class?
    * We can initialize in the member field. 
    * For example int memberA{1};

16. In the expression function, why is the default for the switch-statement to "put back" the token?
    * Because if don't putback the token we "eat" values and this can lead to false results

17. What is "look-ahead"?
    * With look ahead we mean that a rule which is superior should be considered first.
    * For example 2+1*3 
        * 1*3 should be calculated first but the computer reads from left to right
        * Because of that should look ahead if a superior rule is available before performing 2+1

18. What does putback() do and why is it useful?
    * It copies the token and sets the buffer boolean to true.
    * It is useful because we know that we have to consider following terms

19. Why the remainder (modulus) operation, %, difficult to implement in the term()?
    * The remainder operation is difficult because its only suits to integers and we deal with floating point numbers.

20. What do we use the two data members of the Token class for?
    * With the full and buffer we can show if a token is in the buffer and which value it have

21. Why do we (sometimes) split a class's members into private and public members.
    * Because of we want to encapsulate information for the caller of the method that should not be modified
    * public members are meant to be accessed and private are for the class to function properly

22. What happens in the Token_stream class when there is a token in buffer and the get() function is called?
    * Firstly it check if there is a token inside the buffer. If its true than the the token will be removed from the buffer and the indicator (full) will be set to false.

23. Why were the ';' and 'q' characters added to the switch-statement in the get() function of the Token_stream class?
    * The semicolon triggers the printing of the result and shows the program that the user finished its command
    * The character q shows the program that the user wants to terminate this session

24. When should we start testing our program?
    * The earlier you test you should prevent big issues. So after a small prototype testing should be reasonable.

25. What is a "user-defined type"? Why would we want one?
    * A user defined type can be class or a struct that representing a type specially designed for our problem.
    * Using a user defined type is useful because we can provide others and us a valid type

26. What is the interface to a C++ "user-defined type"?
    * The interface are members or functions (methods) which can be accessed from outside of an user-defined type

27. Why do we want to rely on libraries of code?
    * Because it is a good idea to use tested, optimized code that are in libraries
    * We benefit from preventing reinventing frequently performed actions and our codebase will be smaller and easier to grasp

# Chapter  7:  Completing a program
1. What is the purpose of working on the program after the first version works? Give a list of reasons.
    * The first version is mostly full of bugs and logical errors
    * We want to add new features
    * We want to improve performanceS

2. Why does 1+2; q typed into the calculator not quit after it receives an error?
    * Cannot reconstruct the error with my compiler

3. Why did we choose to make a constant character called number?
    * This constant representing all numeric values and is inserted into Tokens kind member variable. 

4. We split main() into two separate functions. What does the new function do and why did we split main()?
    * We split the main because the first section deals with correct running
    * The second section is for error handling (divided into know and unknown errors)

5. Why do we split code into multiple functions? State principles.
    * We mostly split code for better readability and easier debugging
    * We split "calculations" into logical functions that does a specific job 

6. What is the purpose of commenting and how should it be done?
    * The purpose of commenting is to make comprehending easier for a different person 
    * The purpose is not write the code into human language, because mostly person with understanding of this language reads the code

7. What does narrow_cast do?
    * narrow_cast ensures that no information is lost while casting

8. What is the use of symbolic constants?
    * Symbolic constants are values that represent a type with a arbitrary selected value. For example '8' is in the calculator program 
    * the representation of numeric values

9. Why do we care about code layout?
    * Better readability
    * Bugs can better hide in "ugly" code

10. How do we handle % (remainder) of floating-point numbers?
    * Checking with fmod(d,1) != 0

11. What does is_declared() do and how does it work?
    * Checks if the declaration is done before
    * Preventing double declaration

12. The input representation for let is more than one character. How is it accepted as a single token in the modified code?
    * We check in the default case in the switch if the concatenated string s is equal to let
    * If this is true than we create a token with a single letter 

13. What are the rules for what names can and cannot be in the calculator program?
    * The names should be misleading like pi is unequal to the mathematical pi
    * Non asci letters are not supported

14. Why is it a good idea to build a program incrementally?
    * It provides the possibility to test logical units after moving on to the next logical
    * Easier to catch errors 

15. When do you start to test?
    * As soon you can compile your code

16. When do you retest?
    * When project is finished or a change is made

17. How do you decide what should be a separate function?
    * A function should do only one job 
    * A function must be logically divided from other tasks

18. How do you choose names for variables and functions? List possible reasons.
    * The name of a variable should represent its function 'i' is a bad example because no one what it is
    * Better alternative for iterations are for example 'numIteration' or 'numElement' if iterating through a vector

19. Why do you add comments?
    * To grasp the idea of this section

20. What should be in comments and what should not?
    * Rewriting the code in "human" language

21. When do we consider a program finished?
    * When it does the specified job good enough with the resources we want to invest

# Chapter 8: Technicalities: Functions, etc.
1. What is the difference between a declaration and a definition?
    * A declaration is a statement that introduce a name into a scope with its type
    * A definition specifies exactly what a name refers to and sets memory aside for that variable
        * Multiple declarations are possible but not multiple definitions

2. How do we syntactically distinguish between a function declaration and a function definition?
    * A function declaration supplies the type and can be understood as an interface to describe the function
    * A function definition supplies the function body and what statements need to be executed

3. How do we syntactically distinguish between a variable declaration and a variable definition?
    * Declaration supplies the type
    * Definition supplies the object (the memory)

4. Why can't you use the functions in the calculator program from Chapter 6 without declaring them first?
    * Because we need to forward declare the function to inform the compiler that this functions will be used but the definition is somewhere else
    * For large projects this is necessary to avoid time consuming designing which object to define first

5. Is int a; a definition or just a declaration?
    * This is only a declaration, because its only defines its type without providing a value

6. Why is it a good idea to initialize variables as they are declared?
    * Not all types will initialize/define variable when declared like strings or vectors
    * Because of this the value of the variable can be everything 

7. What can a function declaration consist of?
    * Pattern: "return type" "function name"("type of" arguments/parameter); (Semicolon is necessary if only declaring)
    * For example double squareRoot(double input)

8. What good does indentation do?
    * Better readability
    * Function bodies and scopes are easier to track

9. What are header files used for?
    * The header files are collections of of declarations which are included into source files if needed

10. What is the scope of a declaration?
    * From the point the declaration until the end of the scope (local/global etc.)

11. What kinds of scope are there? Give an example of each.
    * Global scope
        * The area of text outside any other scopes
        * For example  
            * int i{}; --> global scope
            * int main(){}
    * Namespace scope
        * namespace example{int i{};} --> i is inside the namespace scope
    * Class scope
        * Class C{ int i{};}
            * i is in the class scope (member variable)
    * Statement scope
        * For example
            * for (int numElement; numElement<10; ++numElement) {}; --> numElement is a statement scope

12. What is the difference between a class scope and local scope?
    * The variables inside the class scope lives until the class is destroyed
    * The local scope variable are deleted as soon it reach the end 

13. Why should a programmer minimize the number of global variables?
    * The use of global variables should be as low as possible 
    * Because large programs have a lots of variable and if there are to many global variables it is difficult to guarantee if the global variable is still valid
    * It is possible to have collisions 

14. What is the difference between pass-by-value and pass-by-reference?
    * Pass-by-Value copies the object and the rvalue is passed
    * Pass-by-reference doesn't create a copy and gives the address of the variable (rvalue)

15. What is the difference between pass-by-reference and pass-by-const-reference?
    *  Pass-by-const-reference also providing the rvalue but guarantees that the value cannot be changed

16. What is a swap()?
    * A swap swapping two values. 
    * For example A = 10; B = 20; swap(A,B) --> A = 20; B = 10;

17. Would you ever define a function with a vector<double>-by-value parameter?
    * Probably not if i am not absolute sure that the vector will be very small

18. Give an example of undefined order of evaluation. Why can undefined order of evaluation be a problem?
    * Example:  int x = ++i + ++i;
    * This is a problem because every compiler can threat this different 

19. What do x&&y and x||y, respectively, mean?
    * Both are comparison operators first is "and" and the second is "or"

20. Which of the following is standard-conforming C++: functions within functions, functions within classes, classes within classes, classes within functions?
    * functions within functions
        * Not legal in C++
    * Function within classes 
        * Common and useful
    * Classes within classes
        * Useful but only in complex problems 
    * Classes within functions
        * Valid but not best practice --> Should be avoided

21. What goes into an activation record?
    * Locals of the callee
    * Return address of the caller
    * Parameters of the callee
    * Previous stack pointer

22. What is a call stack and why do we need one?
    * The call stack is a data structure which grows and shrinks with "Last in, first out"
    * Data structure that stores information about the active subroutines of a computer program

23. What is the purpose of a namespace?
    * To provide a tool for organizing functions, data, and types into a type
    * To prevent collisions for example of two identical function names

24. How does a namespace differ from a class?
    * Classes and structs define types. You can create an object of a type. 
    * Namespaces simply declare a scope inside which other types, functions, objects, or namespaces can exist.

25. What is a using declaration?
    * Introduces a name that is defined elsewhere into the declarative region where this using-declaration appears.

26. Why should you avoid using directives in a header?
    * The using declaration can call a unwanted function or provide a false variable.
    * For example you wanted to call B::func() but you have a using A::func; before you call just func()
        * This using call the A::func instead the wanted B::func

27. What is namespace std?
    * The std namespace is the namespace for the standard C++ library
        * This standard library is a collection of classes and function, which are part of the C++ ISO standard

# Chapter 9: Technicalities: Classes, etc.
1. What are the two parts of a class, as described in the chapter?
    * Data members -> Attribute
    * Function members -> methods

2. What is the difference between the interface and the implementation in a class?
    * Interface is the part where the user access directly (Public)
    * Implementation is the part that is called indirectly (Private)

3. What are the limitations and problems of the original Date struct that is created in the chapter?
    * Direct access to the member variable is not best practice
    * No checks for valid inputs for example negative years etc.
    * No constructor was used at first, which bloats up the declaration of a legit date

4. Why is a constructor used for the Date type instead of an init_day() function?
    * Because with a constructor the possibility to create an invalid date is minimized
    * It's convenient because other variables are defined alike

5. What is an invariant? Give examples.
    * A invariant is a valid value of a given type. 
    * Example: A invariant Date can be a valid date in the past, present or future

6. When should functions be put in the class definition, and when should they be defined outside the class? Why?
    * Function which are used inside a class for example when modifying attributes should be defined inside a class
    * Function which are no directly related to the class should be implemented outside the class
    * Because with this practice we can use general purpose function for other classes and encapsulate class specific operations

7. When should operator overloading be used in a program? Give a list of operators that you might want to overload (each with a reason).
    * We overloading operators when we want to provide a conventional notation for the types we create. 
    * For example when we want to print something with std::cout we overload << to define how the user defined type is to printed
    * List of possible overloading
        * ++ Increment -> To define how a user defined type is to incremented
        * -- Decrement -> To define how a user defined type is to decremented
        * << Extraction -> For example how to print user defined types
        * <, >, == -> To compare two user defined types

8. Why should the public interface to a class be as small as possible?
    * Because we provide only functions that are needed (feature creep)
    * Easier to debug because of lesser function to be checked

9. What does adding const to a member function do?
    * A const member function guarantees that a function doesn't change member variables
    * For example getter methods should be const

10. Why are "helper functions" best placed outside the class definition?
    * Because helper functions could be used for different user defined types
    * For adding new functionality which isn't needed in a class

# Chapter 10: Input and Output Streams
1. When dealing with input and output, how is the variety of devices dealt with in most modern computers?
    * The I/O Library provide a layer of abstraction of I/O
    * Because of the library mostly a device specific in or output is not needed 

2. What, fundamentally, does an istream do?
    * istream deals with streams of input

3. What, fundamentally, does an ostream do?
    * ostream deals with streams of output

4. What, fundamentally, is a file?
    * At the most basic level is a file simply a sequence of bytes numbered 0 upwards

5. What is a file format?
    * A file format describes the rules that determine what the byte stream of mean.

6. Name four different types of devices that can require I/O for a program.
    * Stream of data items (files, networks, display devices)
    * Interaction with a keyboard
    * Interaction through a graphical interface
    * Interaction with a mouse

7. What are the four steps for reading a file?
    * 1: Know the name of the file
    * 2: Open the file for reading
    * 3: Read in the characters of that file
    * 4: Close the file (typically done implicitly)

8. What are the four steps for writing a file?
    * 1: Name the file
    * 2: Open the file for writing
    * 3: Write out desired objects into file
    * 4: Close the file (typically done implicitly) 

9. Name and define the four stream states.
    * good() -> The operations succeeded
    * eof() -> We hit end of input (end of file)
    * fail() -> Something unexpected happened (for example: wanted a digit get an char)
    * bad() -> Something unexpected and serious happened (for example: disk read error)

10. Discuss how the following input problems can be resolved:
    * The user typing an out-of-range value
        * We can check if stream is corrupted with cin.bad() and can throw an error
    * Getting no value (end of file)
        * We check if std::cin.eof() is true
    * The user typing something of the wrong type
        * We check for fail and recover std::cin with clear()

11. In what way is input usually harder than output?
    * Because our logic and how the data is outputted is in the hands of the programmer

12. In what way is output usually harder than input?
    * When we deals with special devices
    * When the type we want to output is complex

13. Why do we (often) want to separate input and output from computation?
    * Because for correct computation the in/output must be done correct
    * If we do computation in the same time or scope we can get false results

14. What are the two most common uses of the istream member function clear()?
    * To set the state to good()
    * To continue input after an fail()

15. What are the usual function declarations for << and >> for a user-defined type X?
    * std::istream& operator>>(std::istream& is, Class& XYZ)
    * std::ostream& operator<<(std::istream& is, const Class& XYZ)

# Chapter 11: Customizing Input and Output
1. Why is  I/O tricky for a programmer? 
    * I/O is tricky because there are many different data types and the interpretation can vary alot.
    * For example 1234 can be understood as ints 1, 2, 3,4; as chars or as the string "1234"
    * Because of that it is not always trivial what the person or data meant with given out or input

2. What does the <<hex do?
    * This is a I/O manipulator which changes the output of the I/O stream
    * For example the integer 255 would be displayed as FF in hex.

3. What are hexadecimal numbers used for in computer science? Why?
    * Because two characters in hex like FF are exactly one  byte (8 bit) and the readablity of a hex stream is better

4. Name some of the options you may want to implement for formatting integer outputs.
    * I probably will use showbase to easier determine which reprensentation the int is

5. What is a manipulator?
    * A manipulator changes the behavoir of a stream

6. What is the prefix for decimal? For octal? For hexadecimal?
    * decimal -> std::dec
    * octal -> std::oct
    * hexadecimal -> std::hex

7. What is the default output format for floating-point values?
    * std::defaultfloat is the default, which is also known as general format

8. What is a field?
    * Fiels specify how many characters an integer or string will occupy
    * For that we use the function "set field width" -> setw()

9. Explain what setprecision() and setw() do.
    * setprecision() is a manipulator for floating point, regarding of reprensentation 
        * defaultfloat -> precision is the total number of digits
        * scientific -> precision is the number of digits after the decimal point
        * fixed -> precision is the number of digits after the decimal point
    * setw() specify how many characters a output will have 
        * Prints 1234 when setw(2) is setted, because data will not be cutted

10. What is the purpose of file open modes?
    * The different file open modes are used for specific purposes
        * Reading files (ifstream)
        * Writing files (ostream)
        * Appending to existing files (app)
        * Binary mode

11. Which of the following manipulators does not "stick": hex, scientific, setprecision(), showbase, setw?
    * setw only is applied to the next input/output field

12. What  is the difference between character I/O and binary I/O?
    * The character I/O is the default and read the stream as characters
    * Binary I/O reads the the I/O as binary values, but if not necessary don't use it

13. Give an example of when it would probably be beneficial to use a binary file instead of a text file?
    * When reading image or sound files because the values are just bits and doesn't have a good character reprensentation

14. Give two example where a stringstream can be useful?
    * stringstream is used when the processing is done separate from the actual I/O
    * When we want to tailor the I/O for the task

15. What is a file position?
    * A file position is used when the intention is to write or read a specific place in the file.

16. What happens if you position a file position beyon the end of file?
    * Is OS dependend and undefined behavoir

17. When would you prefer line-oriented input to type-specific input?
    * For example, when we want to use the full input without the separation with withspaces

18. What does isalnum(c) do?
    * Checks if the input Alphanumeric



