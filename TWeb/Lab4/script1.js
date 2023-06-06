function check() {
  const quizAnswers = [
    "scour",
    "swap",
    "scatter",
    "thick",
    "drought",
    "rescue",
    "reierate",
    "soup",
    "prediction",
    "hold over",
  ];
  let correct = 0;

  for (let i = 1; i <= quizAnswers.length; i++) {
    const quiz = document.getElementById(`quiz${i}`).value.toLowerCase();
    if (quiz === quizAnswers[i - 1]) {
      correct++;
    }
  }

  const resultElement = document.getElementById("result");
  resultElement.innerHTML = `Ai raspuns corect la ${correct}  din ${quizAnswers.length} întrebări!`;
}

function refresh() {
  location.reload();
}
