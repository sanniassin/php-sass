# PHP-SASS: A wrapper for libsass of PHP

## Install

See [INSTALL](https://github.com/guitarpoet/php-sass/blob/master/INSTALL)

## Play with it

After the install. You can just interact with the compiler using these php functions:

	sass_version() // This will return the current libsass's version
	sass_compile(string $type, string $data, array $options, string $error) //

## Sass Compile

You can compile the sass file or sass string using the sass_compile function, the args are:

1. string $type: The type of the sass compiling, support data or file
2. string $data: File name when in file type, will search every include path to find the file, sass string when the data type
3. array $options: The sass compiler's options, will describe more detail in next section
4. string $error: The error string, if got any compiling error, you can check for this variable


So, a typical usage is like this:

	$options = array(
		"include_path": getcwd()
	);

	$error = "";

	$result = sass_compile("data", "foo { font-size: 2*2px; }", $options, $error);

	if($result)
		echo $result;
	else
		echo $error;

or

	$result = sass_compile("file", "foo.scss", $options, $error);

## Sass Options

Here is the options you can have for sass compiler:

- precision
- output_style: Support 0 ~ 4, 0 is default
	- SASS_FORMAT_NESTED - 0
	- SASS_FORMAT_EXPANDED - 1
	- SASS_FORMAT_COMPACT - 2
	- SASS_FORMAT_COMPRESSED - 3
	- SASS_FORMAT_FORMATTED - 4
- source_comments
- source_map_embeded
- source_map_contents
- omit_source_map_url
- is_indented_syntax_src
- indent
- linefeed
- input_path
- output_path
- image_path
- include_path
- source_map_file

## Features

1. Fully wrap for libsass
2. Fully support the options of libsass
3. Provide the php function to libsass, so you can call any php function as libsass's function, like this php(time) or php(count_down, 1, 2, 3)
4. Fully support all kinds of type in the sass and can translate them to php and back
5. Extended C functions for Sass Compiler

## Extended Sass Builtin Functions

Math Functions:

	math-pow($i, $n) // The same pow function as math.h

