-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Wrz 18, 2023 at 12:55 PM
-- Wersja serwera: 10.4.28-MariaDB
-- Wersja PHP: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `baza1`
--
CREATE DATABASE IF NOT EXISTS `baza1` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_polish_ci;
USE `baza1`;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `nauczyciele`
--

CREATE TABLE `nauczyciele` (
  `id_nauczyciela` int(11) UNSIGNED NOT NULL,
  `nauczyciel` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_polish_ci;

--
-- Dumping data for table `nauczyciele`
--

INSERT INTO `nauczyciele` (`id_nauczyciela`, `nauczyciel`) VALUES
(1, 'Chris Potyrala'),
(3, 'Marek Pałkowski'),
(7, 'Mriosław Mościcki'),
(10, 'Dorota Kowalczyk');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `oceny`
--

CREATE TABLE `oceny` (
  `id_oceny` int(11) UNSIGNED NOT NULL,
  `ocena` int(10) UNSIGNED NOT NULL,
  `id_uczen` int(11) UNSIGNED NOT NULL,
  `id_nauczyciel` int(11) UNSIGNED NOT NULL,
  `id_przedmiot` int(11) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_polish_ci;

--
-- Dumping data for table `oceny`
--

INSERT INTO `oceny` (`id_oceny`, `ocena`, `id_uczen`, `id_nauczyciel`, `id_przedmiot`) VALUES
(1, 5, 7, 3, 4),
(2, 4, 1, 1, 1),
(5, 3, 5, 10, 6),
(7, 6, 3, 1, 2);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `przedmioty`
--

CREATE TABLE `przedmioty` (
  `id_przedmioty` int(11) UNSIGNED NOT NULL,
  `przedmioty` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_polish_ci;

--
-- Dumping data for table `przedmioty`
--

INSERT INTO `przedmioty` (`id_przedmioty`, `przedmioty`) VALUES
(6, 'Matematyka'),
(1, 'PAI'),
(2, 'polski'),
(4, 'PSI');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `uczniowie`
--

CREATE TABLE `uczniowie` (
  `id_ucznia` int(11) UNSIGNED NOT NULL,
  `uczen` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_polish_ci;

--
-- Dumping data for table `uczniowie`
--

INSERT INTO `uczniowie` (`id_ucznia`, `uczen`) VALUES
(1, 'Nowicki Ala'),
(2, 'Srerbny Jozef'),
(3, 'Szybki Maciek'),
(4, 'Spragniony Kuba'),
(5, 'Sok Swiat'),
(7, 'Wolny Joe');

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `nauczyciele`
--
ALTER TABLE `nauczyciele`
  ADD PRIMARY KEY (`id_nauczyciela`);

--
-- Indeksy dla tabeli `oceny`
--
ALTER TABLE `oceny`
  ADD PRIMARY KEY (`id_oceny`),
  ADD KEY `id_uczen` (`id_uczen`),
  ADD KEY `id_nauczyciel` (`id_nauczyciel`),
  ADD KEY `id_przedmiot` (`id_przedmiot`);

--
-- Indeksy dla tabeli `przedmioty`
--
ALTER TABLE `przedmioty`
  ADD PRIMARY KEY (`id_przedmioty`),
  ADD UNIQUE KEY `przedmioty` (`przedmioty`);

--
-- Indeksy dla tabeli `uczniowie`
--
ALTER TABLE `uczniowie`
  ADD PRIMARY KEY (`id_ucznia`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `uczniowie`
--
ALTER TABLE `uczniowie`
  MODIFY `id_ucznia` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `oceny`
--
ALTER TABLE `oceny`
  ADD CONSTRAINT `oceny_ibfk_1` FOREIGN KEY (`id_nauczyciel`) REFERENCES `nauczyciele` (`id_nauczyciela`),
  ADD CONSTRAINT `oceny_ibfk_2` FOREIGN KEY (`id_przedmiot`) REFERENCES `przedmioty` (`id_przedmioty`),
  ADD CONSTRAINT `oceny_ibfk_3` FOREIGN KEY (`id_oceny`) REFERENCES `uczniowie` (`id_ucznia`),
  ADD CONSTRAINT `oceny_ibfk_4` FOREIGN KEY (`id_uczen`) REFERENCES `uczniowie` (`id_ucznia`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
