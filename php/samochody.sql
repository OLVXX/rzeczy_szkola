-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Wrz 25, 2023 at 01:09 PM
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
-- Database: `samochody`
--
CREATE DATABASE IF NOT EXISTS `samochody` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_polish_ci;
USE `samochody`;

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `komis`
--

CREATE TABLE `komis` (
  `id` int(11) UNSIGNED NOT NULL,
  `id_model` int(11) UNSIGNED NOT NULL,
  `cena` bigint(20) UNSIGNED NOT NULL,
  `przebieg` bigint(20) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_polish_ci;

--
-- Dumping data for table `komis`
--

INSERT INTO `komis` (`id`, `id_model`, `cena`, `przebieg`) VALUES
(1, 1, 50000, 15000),
(2, 4, 18000, 400000),
(3, 5, 150000, 20000),
(4, 5, 120000, 40000),
(5, 3, 200000, 10),
(6, 8, 300000, 12000);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `marka`
--

CREATE TABLE `marka` (
  `id` int(11) UNSIGNED NOT NULL,
  `marka` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_polish_ci;

--
-- Dumping data for table `marka`
--

INSERT INTO `marka` (`id`, `marka`) VALUES
(1, 'mercedes'),
(2, 'bmw'),
(3, 'opel'),
(4, 'audi'),
(5, 'porsche'),
(6, 'volzwagen'),
(7, 'skoda'),
(8, 'Seat'),
(9, 'citroen'),
(10, 'pegout'),
(11, 'Ranault'),
(12, 'Bugatti'),
(13, 'volvo'),
(14, 'saab');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `modele`
--

CREATE TABLE `modele` (
  `id` int(11) UNSIGNED NOT NULL,
  `model` varchar(50) NOT NULL,
  `id_marka` int(11) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_polish_ci;

--
-- Dumping data for table `modele`
--

INSERT INTO `modele` (`id`, `model`, `id_marka`) VALUES
(1, '3', 2),
(2, '5', 2),
(3, 'passat', 6),
(4, 'golf', 6),
(5, 'c5', 9),
(6, 'cactus', 9),
(7, 'supra', 20),
(8, 'impreza', 21);

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `komis`
--
ALTER TABLE `komis`
  ADD PRIMARY KEY (`id`);

--
-- Indeksy dla tabeli `marka`
--
ALTER TABLE `marka`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `komis`
--
ALTER TABLE `komis`
  MODIFY `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `marka`
--
ALTER TABLE `marka`
  MODIFY `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
