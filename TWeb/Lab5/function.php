<?php
if (isset($_POST['functionName'])) {
    $functionName = $_POST['functionName'];
    switch ($functionName) {
        case 'fprintf':
            $info = "Writes a formatted string to the stream.";
            break;
        case 'get_class':
            $info = "Returns the name of the class to which the object belongs.";
            break;
        case 'array_fill':
            $info = "Fills an array with values.";
            break;
		case 'implode':
			$info = "Concatenates the elements of an array into a string.";
            break;
		case 'array_pop':
			$info = "Retrieves the last element of an array.";
            break;
		case 'array_replace':
			$info = "Replaces the elements of an array with elements of other passed arrays.";
            break;
		case 'strrev':
			$info = "Flips a string backwards.";
            break;
		case 'trim':
			$info = "Removes spaces (or other characters) from the beginning and end of a string.";
            break;
        default:
            $info = "We have no information about such a function.";
            break;
    }
    echo $info;
}
?>
