-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: Jan 20, 2021 at 04:33 PM
-- Server version: 5.7.31
-- PHP Version: 7.3.21

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `bdbsms`
--

-- --------------------------------------------------------

--
-- Table structure for table `bookinfo`
--

DROP TABLE IF EXISTS `bookinfo`;
CREATE TABLE IF NOT EXISTS `bookinfo` (
  `ISBN` varchar(50) COLLATE utf8mb4_bin NOT NULL,
  `AuthorName` varchar(60) COLLATE utf8mb4_bin NOT NULL,
  `BookTitle` varchar(200) COLLATE utf8mb4_bin NOT NULL,
  `Year` int(10) DEFAULT NULL,
  `Price` double NOT NULL,
  `BookQuantity` int(200) NOT NULL,
  PRIMARY KEY (`ISBN`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `bookinfo`
--

INSERT INTO `bookinfo` (`ISBN`, `AuthorName`, `BookTitle`, `Year`, `Price`, `BookQuantity`) VALUES
('123-111-121-141', 'DR', 'OOP', 2020, 30, 40),
('111-222-333-123', 'Dr.Hadrien Jean', 'Statistic and probability', 2005, 35, 110),
('123-112-121-11', 'Dr.  Raghu Ramakrishnan', 'Database Design', 2010, 25, 98),
('132-112-112-142', 'PROFESOR MADYA TS. DR. SABRINA BINTI AHMAD', 'OOP Book', 2020, 40, 58),
('123-23123-332', 'Ts. Maslita Binti Abd Aziz', 'OS Book', 2020, 30, 55),
('145-144-456', 'Dr. Tahmid Choudhury', 'Data Structure', 2001, 20, 195),
('178-789-778-700', 'Dr. Kozen', 'Algorithm Analysis', 2015, 27, 58);

-- --------------------------------------------------------

--
-- Table structure for table `cart`
--

DROP TABLE IF EXISTS `cart`;
CREATE TABLE IF NOT EXISTS `cart` (
  `ISBN` varchar(50) COLLATE utf8mb4_bin NOT NULL,
  `Price` double NOT NULL,
  `BookTitle` varchar(200) COLLATE utf8mb4_bin NOT NULL,
  `CartID` int(11) NOT NULL AUTO_INCREMENT,
  `CustomerID` int(100) DEFAULT NULL,
  `Quantity` int(11) DEFAULT NULL,
  PRIMARY KEY (`CartID`),
  KEY `Cart_ISBN_FK` (`ISBN`)
) ENGINE=MyISAM AUTO_INCREMENT=93 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
CREATE TABLE IF NOT EXISTS `customer` (
  `CustomerID` int(11) NOT NULL AUTO_INCREMENT,
  `CustomerName` varchar(60) COLLATE utf8mb4_bin NOT NULL,
  `CustomerEmail` varchar(100) COLLATE utf8mb4_bin DEFAULT NULL,
  `PhoneNumber` varchar(50) COLLATE utf8mb4_bin DEFAULT NULL,
  `UserName` varchar(60) COLLATE utf8mb4_bin NOT NULL,
  `UserPassword` varchar(100) COLLATE utf8mb4_bin NOT NULL,
  PRIMARY KEY (`CustomerID`)
) ENGINE=MyISAM AUTO_INCREMENT=33 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`CustomerID`, `CustomerName`, `CustomerEmail`, `PhoneNumber`, `UserName`, `UserPassword`) VALUES
(32, 'Aminuzzaman Niloy', 'zamanniloy404@gmail.com', '0147376212', 'niloy', '2001'),
(31, 'Shadman zoha', 'shadmanzoha90@gmail.com', '0147376215', 'zoha', 'zoha'),
(30, 'Farabi Tasnim Ahmed', 'tasnimfarabi25@gmail.com', '01111362895', 'farabi25', '1234'),
(29, '123', '6776', 'gfgfg', '666', '343');

-- --------------------------------------------------------

--
-- Table structure for table `promotion`
--

DROP TABLE IF EXISTS `promotion`;
CREATE TABLE IF NOT EXISTS `promotion` (
  `PromotionID` int(11) NOT NULL AUTO_INCREMENT,
  `Percentage` int(11) NOT NULL,
  PRIMARY KEY (`PromotionID`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `promotion`
--

INSERT INTO `promotion` (`PromotionID`, `Percentage`) VALUES
(1, 20);

-- --------------------------------------------------------

--
-- Table structure for table `purchase`
--

DROP TABLE IF EXISTS `purchase`;
CREATE TABLE IF NOT EXISTS `purchase` (
  `TotalPrice` double NOT NULL,
  `PurchaseID` int(11) NOT NULL AUTO_INCREMENT,
  `promotionprice` double DEFAULT NULL,
  `Customerid` int(100) DEFAULT NULL,
  PRIMARY KEY (`PurchaseID`)
) ENGINE=MyISAM AUTO_INCREMENT=101 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `purchase`
--

INSERT INTO `purchase` (`TotalPrice`, `PurchaseID`, `promotionprice`, `Customerid`) VALUES
(130, 100, 104, 32),
(154, 99, 123.2, 32),
(600, 98, 480, 31),
(450, 97, 360, 31),
(300, 96, 150, 30),
(150, 95, 75, 30),
(170, 94, 85, 30);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
