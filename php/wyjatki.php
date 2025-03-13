<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>wyjatkil</title>
</head>
<body>
    <?php
    //zad1
   function dzie  l($licznik, $mianownik) {
    if ($mianownik == 0) {
        throw new Exception("Nie można dzielić przez zero!");
    }
    return $licznik / $mianownik;
}

try {
    echo dziel(10, 0);
} catch (Exception $e) {
    echo "Błąd w linii: " . $e->getLine() . ": " . $e->getMessage();
}

// Zad2
function obliczPoleProstokata($dlugosc, $szerokosc) {
    if ($dlugosc < 0 || $szerokosc < 0) {
        throw new Exception("Boki prostokąta nie mogą być ujemne!");
    }
    return $dlugosc * $szerokosc;
}

try {
    echo obliczPoleProstokata(-1, 5);
} catch (Exception $e) {
    echo "Błąd w linii: " . $e->getLine() . ": " . $e->getMessage();
}

   
   // Zad3
   function openFile($filename) {
       if (!file_exists($filename)) {
           throw new Exception("Plik nie istnieje!");
       }
       return fopen($filename, "r");
   }
   
   try {
       $file = openFile("nieistniejacy_plik.txt");
   } catch (Exception $e) {
       echo "Błąd w linii: " . $e->getLine() . ": " . $e->getMessage();
   }
   ?>
   
</body>
</html>