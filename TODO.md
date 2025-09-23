# Nebula TODO:

#### Implemented Features ✅
* Explicit casting
* Ternary operators
* Getters and setters
* Properties for primitive types
* Foreach
* Better primitive types
* Better operators
* Optional namespace
#### Pending Features ❌
* Named parameters
* Interpolated strings
* Tuples
* NDK: Write the collections namespace
* NDK: Finish the io namespace (Files, etc...)

## Compiler changes
### Explicit casting: ✅
Self explanatory, you cant cast right now.

This throws errors because the compiler's parser doesn't expect `(int)`:
```csharp
int casted = (int)3.4f;
```
Yet to define:
- How do you cast a tuple, should that even be possible?

### Ternary operators:✅
This throws errors because the compiler's parser doesn't expect the syntax:
```csharp
int[] numbers = {1,2,3,4,5};
Console.println((numbers.size > 0 || numbers == null) ? numbers.size : "numbers is empty / uninitialized.");
```

### Getters and setters: ✅
The syntax is exactly the same as in C#:
```csharp
class Person
{
    public string Name  // property
    { get; set; }
}

class Program
{
    static void Main(string[] args)
    {
        Person myObj = new Person();
        myObj.Name = "Liam";
        Console.println(myObj.Name);
    }
}
```

### Properties for primitive types: ✅
```csharp
Console.println(uint16.max); // Outputs: 65,535

int[] numbers = {1,2,3};
Console.println(numbers.size); // Outputs: 3

string word = "hello";
Console.println(word.length); // Outputs: 5
```
Yet to define:
    - How do I implement this? Do I hardcode it in the compiler (this is how the .size property is curently implemented), but what would be the correct way to implement these properties.

### Named parameters:
Named parameters are an optional feature that allows to pass the parameters to any method in any order they want.

Optional parameters define a parameter with a default value with the syntax: `paramName: type? = defaultValue`. Therefore you can ommit that paremeter when calling the method, and it'll use the default value specified.

```csharp
// In this constructor the optionalParamValue of type int is optional, with a default value of 3
public Class(param1: float, optionalParam: int? = 3){}

// This is instantiated with param1 = 3.4f and optionalParam = 3
Class instance1 = new Class(param1: 3.4f); 

// As the parameters are named, you're not tied to the declared order:
// This is instantiated with param1 = 3.4f and optionalParam = 6
Class instance1 = new Class(optionalParam: 6, param1: 3.4f); 
```

You can still use your typical paremeters:

```csharp
// Constructor definition
public Class(float param1, int param2);

// Instancing
Class instance = new Class(valOfParam1, valOfParam2);
```
As these traditional-type parameter definitions aren't named, you can't define optional parameters here, nor call the method with unordered parameters. 


### Foreach: ✅

```csharp
foreach (Type instance in listOfType)
{
    instance.smth(); //Do something
}
```

### Interpolated strings:
Syntax that makes possible to instert literal expressions inside string literals.
```csharp
char dollar = '$';
Console.WriteLine($"An interpolated string has to start with a {dollar}.");
```
### Tuples:

```csharp
(float, uint) t1 = (4.5, 3);
Console.println($"Tuple with elements {t1.Item1} and {t1.Item2}.");
// Output:
// Tuple with elements 4.5 and 3.

(float Sum, uint Count) t2 = (4.5, 3);
Console.println($"Sum of {t2.Count} elements is {t2.Sum}.");
// Output:
// Sum of 3 elements is 4.5.
```

### Optional namespace: ✅

No need to specify a namespace to code. Like wtf, that shouln't be a requirement.

-----

### Better primitive types: ✅

The current primitive types are too ambiguous. They will be replaced with explicit-width types similar to those in C++. The `string` keyword will be a built-in alias for the `nebula.core.String` class.

<style type="text/css">
.tg  {border-collapse:collapse;border-spacing:0;}
.tg td{border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;
overflow:hidden;padding:10px 5px;word-break:normal;}
.tg th{border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;
font-weight:normal;overflow:hidden;padding:10px 5px;word-break:normal;}
.tg .tg-lboi{border-color:inherit;text-align:left;vertical-align:middle}
.tg .tg-u74j{background-color:#F9F9F9;border-color:inherit;font-weight:bold;text-align:center;vertical-align:middle}
.tg .tg-s4x0{background-color:#F9F9F9;border-color:inherit;text-align:center;vertical-align:middle}
.tg .tg-g7sd{border-color:inherit;font-weight:bold;text-align:left;vertical-align:middle}
.tg .tg-0pky{border-color:inherit;text-align:left;vertical-align:top}
</style>

<table class="tg"><thead>
<tr>
<th class="tg-lboi"><span style="font-weight:bold">Category</span></th>
<th class="tg-lboi"><span style="font-weight:bold">Name</span></th>
<th class="tg-lboi"><span style="font-weight:bold">Size in bits</span></th>
<th class="tg-lboi"><span style="font-weight:bold">C++ Equivalent</span></th>
<th class="tg-g7sd">Range / Value</th>
</tr></thead>
<tbody>
<tr>
<td class="tg-lboi">Boolean</td>
<td class="tg-lboi"><code>bool</code></td>
<td class="tg-lboi">8</td>
<td class="tg-lboi"><code>bool</code></td>
<td class="tg-lboi"><code>true</code>, <code>false</code></td>
</tr>
<tr>
<td class="tg-lboi" rowspan="3">Character</td>
<td class="tg-lboi"><code>char</code></td>
<td class="tg-lboi">8</td>
<td class="tg-lboi"><code>char</code></td>
<td class="tg-lboi"><strong>0</strong> to <strong>255</strong> (UTF-8 code unit)</td>
</tr>
<tr>
<td class="tg-lboi"><code>char16</code></td>
<td class="tg-lboi">16</td>
<td class="tg-lboi"><code>char16_t</code></td>
<td class="tg-lboi"><strong>0</strong> to <strong>65,535</strong> (UTF-16 code unit)</td>
</tr>
<tr>
<td class="tg-lboi"><code>char32</code></td>
<td class="tg-lboi">32</td>
<td class="tg-lboi"><code>char32_t</code></td>
<td class="tg-lboi"><strong>0</strong> to <strong>1,114,111</strong> (A single Unicode character)</td>
</tr>
<tr>
<td class="tg-lboi" rowspan="4">Signed Integers</td>
<td class="tg-lboi"><code>byte</code> or <code>int8</code></td>
<td class="tg-lboi">8</td>
<td class="tg-lboi"><code>int8_t</code></td>
<td class="tg-lboi"><strong>-128</strong> to <strong>127</strong></td>
</tr>
<tr>
<td class="tg-lboi"><code>short</code> or <code>int16</code></td>
<td class="tg-lboi">16</td>
<td class="tg-lboi"><code>int16_t</code></td>
<td class="tg-lboi"><strong>-32,768</strong> to <strong>32,767</strong></td>
</tr>
<tr>
<td class="tg-lboi"><code>int</code> or <code>int32</code></td>
<td class="tg-lboi">32</td>
<td class="tg-lboi"><code>int32_t</code></td>
<td class="tg-lboi"><strong>-2,147,483,648</strong> to <strong>2,147,483,647</strong></td>
</tr>
<tr>
<td class="tg-lboi"><code>long</code> or <code>int64</code></td>
<td class="tg-lboi">64</td>
<td class="tg-lboi"><code>int64_t</code></td>
<td class="tg-lboi"><strong>~-9.22 x 10¹⁸</strong> to <strong>~9.22 x 10¹⁸</strong></td>
</tr>
<tr>
<td class="tg-lboi" rowspan="4">Unsigned Integers</td>
<td class="tg-lboi"><code>ubyte</code> or <code>uint8</code></td>
<td class="tg-lboi">8</td>
<td class="tg-lboi"><code>uint8_t</code></td>
<td class="tg-lboi"><strong>0</strong> to <strong>255</strong></td>
</tr>
<tr>
<td class="tg-lboi"><code>ushort</code> or <code>uint16</code></td>
<td class="tg-lboi">16</td>
<td class="tg-lboi"><code>uint16_t</code></td>
<td class="tg-lboi"><strong>0</strong> to <strong>65,535</strong></td>
</tr>
<tr>
<td class="tg-lboi"><code>uint</code> or <code>uint32</code></td>
<td class="tg-lboi">32</td>
<td class="tg-lboi"><code>uint32_t</code></td>
<td class="tg-lboi"><strong>0</strong> to <strong>4,294,967,295</strong></td>
</tr>
<tr>
<td class="tg-lboi"><code>ulong</code> or <code>uint64</code></td>
<td class="tg-lboi">64</td>
<td class="tg-lboi"><code>uint64_t</code></td>
<td class="tg-lboi"><strong>0</strong> to <strong>~1.84 x 10¹⁹</strong></td>
</tr>
<tr>
<td class="tg-lboi" rowspan="2">Floating-Point</td>
<td class="tg-lboi"><code>float</code></td>
<td class="tg-lboi">32</td>
<td class="tg-lboi"><code>float</code></td>
<td class="tg-lboi">Approx. <strong>±3.4 x 10³⁸</strong> (7-digit precision)</td>
</tr>
<tr>
<td class="tg-lboi"><code>double</code></td>
<td class="tg-lboi">64</td>
<td class="tg-lboi"><code>double</code></td>
<td class="tg-lboi">Approx. <strong>±1.7 x 10³⁰⁸ </strong>(15-digit precision)</td>
</tr>
<tr>
<td class="tg-lboi" rowspan="3">Special</td>
<td class="tg-lboi"><code>null</code></td>
<td class="tg-lboi">N/A</td>
<td class="tg-lboi"><code>nullptr_t</code> (C++11)</td>
<td class="tg-lboi">Represents the null pointer value</td>
</tr>
<tr>
<td class="tg-lboi"><code>void</code></td>
<td class="tg-lboi">N/A</td>
<td class="tg-lboi"><code>void</code></td>
<td class="tg-lboi">Represents the absence of a value</td>
</tr>
</tbody></table>

### Better Operators: ✅

Implement a full set of operators for arithmetic, bitwise, and logical operations.

<style type="text/css">
.tg  {border-collapse:collapse;border-spacing:0;}
.tg td{border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;
overflow:hidden;padding:10px 5px;word-break:normal;}
.tg th{border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;
font-weight:normal;overflow:hidden;padding:10px 5px;word-break:normal;}
.tg .tg-lboi{border-color:inherit;text-align:left;vertical-align:middle}
.tg .tg-u74j{background-color:#F9F9F9;border-color:inherit;font-weight:bold;text-align:center;vertical-align:middle}
.tg .tg-s4x0{background-color:#F9F9F9;border-color:inherit;text-align:center;vertical-align:middle}
.tg .tg-g7sd{border-color:inherit;font-weight:bold;text-align:left;vertical-align:middle}
.tg .tg-0pky{border-color:inherit;text-align:left;vertical-align:top}
</style>

<table class="tg"><thead>
<tr>
<th class="tg-lboi"><span style="font-weight:bold">Category</span></th>
<th class="tg-lboi"><span style="font-weight:bold">Operator</span></th>
<th class="tg-lboi"><span style="font-weight:bold">Description</span></th>
</tr></thead>
<tbody>
<tr>
<td class="tg-lboi" rowspan="6"><strong>Arithmetic</strong></td>
<td class="tg-lboi"><code>+</code></td>
<td class="tg-lboi">Addition</td>
</tr>
<tr>
<td class="tg-lboi"><code>-</code></td>
<td class="tg-lboi">Subtraction</td>
</tr>
<tr>
<td class="tg-lboi"><code>*</code></td>
<td class="tg-lboi">Multiplication</td>
</tr>
<tr>
<td class="tg-lboi"><code>/</code></td>
<td class="tg-lboi">Division</td>
</tr>
<tr>
<td class="tg-lboi"><code>%</code></td>
<td class="tg-lboi">Modulo</td>
</tr>
<tr>
<td class="tg-lboi"><code>**</code></td>
<td class="tg-lboi">Power (maps to std::pow)</td>
</tr>
<tr>
<td class="tg-lboi" rowspan="6"><strong>Bitwise</strong></td>
<td class="tg-lboi"><code>&</code></td>
<td class="tg-lboi">Bitwise AND</td>
</tr>
<tr>
<td class="tg-lboi"><code>|</code></td>
<td class="tg-lboi">Bitwise OR</td>
</tr>
<tr>
<td class="tg-lboi"><code>^</code></td>
<td class="tg-lboi">Bitwise XOR</td>
</tr>
<tr>
<td class="tg-lboi"><code>~</code></td>
<td class="tg-lboi">Bitwise NOT</td>
</tr>
<tr>
<td class="tg-lboi"><code>&lt;&lt;</code></td>
<td class="tg-lboi">Left Shift</td>
</tr>
<tr>
<td class="tg-lboi"><code>&gt;&gt;</code></td>
<td class="tg-lboi">Right Shift</td>
</tr>
<tr>
<td class="tg-lboi" rowspan="5"><strong>Logical</strong></td>
<td class="tg-lboi"><code>&&</code></td>
<td class="tg-lboi">Logical AND (short-circuiting)</td>
</tr>
<tr>
<td class="tg-lboi"><code>&</code></td>
<td class="tg-lboi">Logical AND (non-short-circuiting)</td>
</tr>
<tr>
<td class="tg-lboi"><code>||</code></td>
<td class="tg-lboi">Logical OR (short-circuiting)</td>
</tr>
<tr>
<td class="tg-lboi"><code>|</code></td>
<td class="tg-lboi">Logical OR (non-short-circuiting)</td>
</tr>
<tr>
<td class="tg-lboi"><code>!</code></td>
<td class="tg-lboi">Logical NOT</td>
</tr>
<tr>
<td class="tg-lboi" rowspan="11"><strong>Compound<br> Assignment</strong></td>
<td class="tg-lboi"><code>+=</code></td>
<td class="tg-lboi">Add and assign</td>
</tr>
<tr>
<td class="tg-lboi"><code>-=</code></td>
<td class="tg-lboi">Subtract and assign</td>
</tr>
<tr>
<td class="tg-lboi"><code>*=</code></td>
<td class="tg-lboi">Multiply and assign</td>
</tr>
<tr>
<td class="tg-lboi"><code>/=</code></td>
<td class="tg-lboi">Divide and assign</td>
</tr>
<tr>
<td class="tg-lboi"><code>%=</code></td>
<td class="tg-lboi">Modulo and assign</td>
</tr>
<tr>
<td class="tg-lboi"><code>&amp;=</code></td>
<td class="tg-lboi">Bitwise AND and assign</td>
</tr>
<tr>
<td class="tg-lboi"><code>|=</code></td>
<td class="tg-lboi">Bitwise OR and assign</td>
</tr>
<tr>
<td class="tg-lboi"><code>^=</code></td>
<td class="tg-lboi">Bitwise XOR and assign</td>
</tr>
<tr>
<td class="tg-lboi"><code>&lt;&lt;=</code></td>
<td class="tg-lboi">Left Shift and assign</td>
</tr>
<tr>
<td class="tg-lboi"><code>&gt;&gt;=</code></td>
<td class="tg-lboi">Right Shift and assign</td>
</tr>
<tr>
<td class="tg-lboi"><code>**=</code></td>
<td class="tg-lboi">Power and assign</td>
</tr>
</tbody></table>

#### Examples

```csharp
// Arithmetic Operators
int x = 5 + 3; // Addition: x = 8
int y = 5 - 3; // Subtraction: y = 2
int z = 5 * 3; // Multiplication: z = 15
int c = 2 ** 3; // Power: c = 8
int a = 5 / 2; // Division: a = 2 (integer division)
int b = 5 % 2; // Modulo: b = 1

// Bitwise Operators
byte d = 5 & 3; // Bitwise AND: 0101 & 0011 = 0001 (d = 1)
byte e = 5 | 3; // Bitwise OR: 0101 | 0011 = 0111 (e = 7)
byte f = 5 ^ 3; // Bitwise XOR: 0101 ^ 0011 = 0110 (f = 6)
byte g = (byte)~5; // Bitwise NOT: ~0101 = 11111010 (g = 250 for unsigned byte)
byte h = (byte)(5 << 1); // Left Shift: 0101 << 1 = 1010 (h = 10)
byte i = (byte)(5 >> 1); // Right Shift: 0101 >> 1 = 0010 (i = 2)

// Logical Operators
bool result_and = true && false; // Logical AND (short-circuiting): result_and = false
bool result_and_non_short = true & false; // Logical AND (non-short-circuiting): result_and_non_short = false
bool result_or = true || false; // Logical OR (short-circuiting): result_or = true
bool result_or_non_short = true | false; // Logical OR (non-short-circuiting): result_or_non_short = true
bool result_not = !true; // Logical NOT: result_not = false

// Compound Assignment Operators
int j = 5; j += 3; // Add and assign: j = 8
int k = 5; k -= 3; // Subtract and assign: k = 2
int l = 5; l *= 3; // Multiply and assign: l = 15
int t = 2; t **= 3; // Power and assign: t = 8
int m = 5; m /= 2; // Divide and assign: m = 2
int n = 5; n %= 2; // Modulo and assign: n = 1
byte o = 5; o &= 3; // Bitwise AND and assign: o = 1
byte p = 5; p |= 3; // Bitwise OR and assign: p = 7
byte q = 5; q ^= 3; // Bitwise XOR and assign: q = 6
byte r = 5; r <<= 1; // Left Shift and assign: r = 10
byte s = 5; s >>= 1; // Right Shift and assign: s = 2
```

## NDK

### Write the collections namespace

### Finish the io namespace: Files, etc...