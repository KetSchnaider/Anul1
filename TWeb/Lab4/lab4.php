<?php
if(isset($_POST['submit'])){
  $quiz1 = $_POST['quiz1'];
  $quiz2 = $_POST['quiz2'];
  $quiz3 = $_POST['quiz3'];
  $quiz4 = $_POST['quiz4'];
  $quiz5 = $_POST['quiz5'];
  $quiz6 = $_POST['quiz6'];
  $quiz7 = $_POST['quiz7'];
  $quiz8 = $_POST['quiz8'];
  $quiz9 = $_POST['quiz9'];
  $quiz10 = $_POST['quiz10'];

  $file = fopen("date.txt", "w");

  fwrite($file, "Quiz 1: $quiz1\n");
  fwrite($file, "Quiz 2: $quiz2\n");
  fwrite($file, "Quiz 3: $quiz3\n");
  fwrite($file, "Quiz 4: $quiz4\n");
  fwrite($file, "Quiz 5: $quiz5\n");
  fwrite($file, "Quiz 6: $quiz6\n");
  fwrite($file, "Quiz 7: $quiz7\n");
  fwrite($file, "Quiz 8: $quiz8\n");
  fwrite($file, "Quiz 9: $quiz9\n");
  fwrite($file, "Quiz 10: $quiz10\n");

  fclose($file);
}
?>
