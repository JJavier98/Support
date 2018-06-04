<?php
$cookie = "ejercicioPW";
if(!isset($_COOKIE[$cookie])) {
  setcookie("ejercicioPW", time(), time() + (10), '/'); // 86400 = 1 día
  $mensaje = "Bienvenido por primera vez a mi página web";
} else {
  $mensaje = "Hola, su anterior visita fue el ".strftime("%d %B %Y a las %H:%M:%S", $_COOKIE[$cookie]);
  setcookie("ejercicioPW", time(), time() + (10), '/'); // 86400 = 1 día
}  
?>

<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta name="author" content="Francisco Vélez Ocaña">
  <title>Ejercicio 17. Cookies</title>
</head>
<body>
  <?php echo $mensaje; ?>
</body>
</html>
