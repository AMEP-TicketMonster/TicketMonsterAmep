CREATE DATABASE  IF NOT EXISTS `amep06` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci */;
USE `amep06`;
-- MySQL dump 10.13  Distrib 8.0.41, for Win64 (x86_64)
--
-- Host: ubiwan.epsevg.upc.edu    Database: amep06
-- ------------------------------------------------------
-- Server version	5.5.5-10.11.11-MariaDB-0ubuntu0.24.04.2

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Assajos`
--

DROP TABLE IF EXISTS `Assajos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Assajos` (
  `idAssajos` int(11) NOT NULL AUTO_INCREMENT,
  `idGrup` int(11) NOT NULL,
  `idSala` int(11) NOT NULL,
  `idDataSala` int(11) NOT NULL,
  PRIMARY KEY (`idAssajos`),
  KEY `idGrup` (`idGrup`),
  KEY `idSala` (`idSala`),
  KEY `idDataSala` (`idDataSala`),
  CONSTRAINT `Assajos_ibfk_1` FOREIGN KEY (`idGrup`) REFERENCES `GrupsMusicals` (`idGrup`) ON DELETE CASCADE,
  CONSTRAINT `Assajos_ibfk_2` FOREIGN KEY (`idSala`) REFERENCES `Sales` (`idSala`) ON DELETE CASCADE,
  CONSTRAINT `Assajos_ibfk_3` FOREIGN KEY (`idDataSala`) REFERENCES `DataSala` (`idDataSala`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Assajos`
--

LOCK TABLES `Assajos` WRITE;
/*!40000 ALTER TABLE `Assajos` DISABLE KEYS */;
INSERT INTO `Assajos` VALUES (2,2,4,7);
/*!40000 ALTER TABLE `Assajos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ConcertGrups`
--

DROP TABLE IF EXISTS `ConcertGrups`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ConcertGrups` (
  `idConcert` int(11) NOT NULL,
  `idGrup` int(11) NOT NULL,
  PRIMARY KEY (`idConcert`,`idGrup`),
  KEY `idGrup` (`idGrup`),
  CONSTRAINT `ConcertGrups_ibfk_1` FOREIGN KEY (`idConcert`) REFERENCES `Concerts` (`idConcert`) ON DELETE CASCADE,
  CONSTRAINT `ConcertGrups_ibfk_2` FOREIGN KEY (`idGrup`) REFERENCES `GrupsMusicals` (`idGrup`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ConcertGrups`
--

LOCK TABLES `ConcertGrups` WRITE;
/*!40000 ALTER TABLE `ConcertGrups` DISABLE KEYS */;
/*!40000 ALTER TABLE `ConcertGrups` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Concerts`
--

DROP TABLE IF EXISTS `Concerts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Concerts` (
  `idConcert` int(11) NOT NULL AUTO_INCREMENT,
  `nomConcert` varchar(100) DEFAULT NULL,
  `data` date DEFAULT NULL,
  `aforament` int(11) DEFAULT NULL,
  `preu` decimal(10,2) DEFAULT NULL,
  `idUsuariOrganitzador` int(11) DEFAULT NULL,
  `idGenere` int(11) DEFAULT NULL,
  `ubicacio` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`idConcert`),
  KEY `idUsuariOrganitzador` (`idUsuariOrganitzador`),
  KEY `fk_concerts_generes` (`idGenere`),
  CONSTRAINT `Concerts_ibfk_1` FOREIGN KEY (`idUsuariOrganitzador`) REFERENCES `Usuaris` (`idUsuari`) ON DELETE SET NULL,
  CONSTRAINT `fk_concerts_generes` FOREIGN KEY (`idGenere`) REFERENCES `Generes` (`idGenere`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Concerts`
--

LOCK TABLES `Concerts` WRITE;
/*!40000 ALTER TABLE `Concerts` DISABLE KEYS */;
INSERT INTO `Concerts` VALUES (1,'Monster_1','2024-06-05',1000,60.00,1,1,'Barcelona'),(2,'Monster_2','2024-04-05',2000,70.00,2,2,'Madrid'),(3,'Monster_3','2023-04-05',2500,80.00,3,3,'Bilbao');
/*!40000 ALTER TABLE `Concerts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `DataSala`
--

DROP TABLE IF EXISTS `DataSala`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `DataSala` (
  `idDataSala` int(11) NOT NULL AUTO_INCREMENT,
  `dia` date NOT NULL,
  `hora_inici` time NOT NULL,
  `hora_fi` time NOT NULL,
  `idSala` int(11) NOT NULL,
  PRIMARY KEY (`idDataSala`),
  KEY `fk_idSala` (`idSala`),
  CONSTRAINT `fk_idSala` FOREIGN KEY (`idSala`) REFERENCES `Sales` (`idSala`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `DataSala`
--

LOCK TABLES `DataSala` WRITE;
/*!40000 ALTER TABLE `DataSala` DISABLE KEYS */;
INSERT INTO `DataSala` VALUES (7,'2025-05-15','16:00:00','21:00:00',4);
/*!40000 ALTER TABLE `DataSala` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `DisponibilitatSales`
--

DROP TABLE IF EXISTS `DisponibilitatSales`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `DisponibilitatSales` (
  `idDisponibilitat` int(11) NOT NULL AUTO_INCREMENT,
  `idSala` int(11) NOT NULL,
  `idDataSala` int(11) NOT NULL,
  `idEstatSala` int(11) NOT NULL,
  PRIMARY KEY (`idDisponibilitat`),
  KEY `idSala` (`idSala`),
  KEY `idDataSala` (`idDataSala`),
  KEY `idEstatSala` (`idEstatSala`),
  CONSTRAINT `DisponibilitatSales_ibfk_1` FOREIGN KEY (`idSala`) REFERENCES `Sales` (`idSala`) ON DELETE CASCADE,
  CONSTRAINT `DisponibilitatSales_ibfk_2` FOREIGN KEY (`idDataSala`) REFERENCES `DataSala` (`idDataSala`) ON DELETE CASCADE,
  CONSTRAINT `DisponibilitatSales_ibfk_3` FOREIGN KEY (`idEstatSala`) REFERENCES `EstatSala` (`idEstatSala`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `DisponibilitatSales`
--

LOCK TABLES `DisponibilitatSales` WRITE;
/*!40000 ALTER TABLE `DisponibilitatSales` DISABLE KEYS */;
INSERT INTO `DisponibilitatSales` VALUES (3,4,7,2);
/*!40000 ALTER TABLE `DisponibilitatSales` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Entrades`
--

DROP TABLE IF EXISTS `Entrades`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Entrades` (
  `idEntrada` int(11) NOT NULL AUTO_INCREMENT,
  `idUsuariClient` int(11) DEFAULT NULL,
  `idConcert` int(11) DEFAULT NULL,
  `preu` decimal(10,2) DEFAULT NULL,
  `estat` enum('Disponible','Reservada','Comprada','Cancelada') DEFAULT NULL,
  PRIMARY KEY (`idEntrada`),
  KEY `idUsuariClient` (`idUsuariClient`),
  KEY `idConcert` (`idConcert`),
  CONSTRAINT `Entrades_ibfk_1` FOREIGN KEY (`idUsuariClient`) REFERENCES `Usuaris` (`idUsuari`) ON DELETE CASCADE,
  CONSTRAINT `Entrades_ibfk_2` FOREIGN KEY (`idConcert`) REFERENCES `Concerts` (`idConcert`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Entrades`
--

LOCK TABLES `Entrades` WRITE;
/*!40000 ALTER TABLE `Entrades` DISABLE KEYS */;
/*!40000 ALTER TABLE `Entrades` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `EstatSala`
--

DROP TABLE IF EXISTS `EstatSala`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `EstatSala` (
  `idEstatSala` int(11) NOT NULL AUTO_INCREMENT,
  `estat` enum('Disponible','Reservada') NOT NULL,
  PRIMARY KEY (`idEstatSala`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `EstatSala`
--

LOCK TABLES `EstatSala` WRITE;
/*!40000 ALTER TABLE `EstatSala` DISABLE KEYS */;
INSERT INTO `EstatSala` VALUES (1,'Disponible'),(2,'Reservada');
/*!40000 ALTER TABLE `EstatSala` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Generes`
--

DROP TABLE IF EXISTS `Generes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Generes` (
  `idGenere` int(11) NOT NULL AUTO_INCREMENT,
  `nomGenere` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`idGenere`),
  UNIQUE KEY `nomGenere` (`nomGenere`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Generes`
--

LOCK TABLES `Generes` WRITE;
/*!40000 ALTER TABLE `Generes` DISABLE KEYS */;
INSERT INTO `Generes` VALUES (6,'Classical'),(5,'Electronic'),(4,'Jazz'),(1,'Pop'),(3,'Reggaeton'),(2,'Rock');
/*!40000 ALTER TABLE `Generes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `GrupsMusicals`
--

DROP TABLE IF EXISTS `GrupsMusicals`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `GrupsMusicals` (
  `idGrup` int(11) NOT NULL AUTO_INCREMENT,
  `nomGrup` varchar(150) NOT NULL,
  PRIMARY KEY (`idGrup`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `GrupsMusicals`
--

LOCK TABLES `GrupsMusicals` WRITE;
/*!40000 ALTER TABLE `GrupsMusicals` DISABLE KEYS */;
INSERT INTO `GrupsMusicals` VALUES (1,'TheTyets'),(2,'Rosalia'),(3,'Taylor Swift');
/*!40000 ALTER TABLE `GrupsMusicals` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Roles`
--

DROP TABLE IF EXISTS `Roles`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Roles` (
  `idRol` int(11) NOT NULL AUTO_INCREMENT,
  `nomRol` enum('Administrador','Client','Organitzador') DEFAULT NULL,
  PRIMARY KEY (`idRol`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Roles`
--

LOCK TABLES `Roles` WRITE;
/*!40000 ALTER TABLE `Roles` DISABLE KEYS */;
/*!40000 ALTER TABLE `Roles` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Sales`
--

DROP TABLE IF EXISTS `Sales`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Sales` (
  `idSala` int(11) NOT NULL AUTO_INCREMENT,
  `nom` varchar(100) NOT NULL,
  `ciutat` varchar(255) NOT NULL,
  `capacitat` int(11) NOT NULL CHECK (`capacitat` > 0),
  PRIMARY KEY (`idSala`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Sales`
--

LOCK TABLES `Sales` WRITE;
/*!40000 ALTER TABLE `Sales` DISABLE KEYS */;
INSERT INTO `Sales` VALUES (1,'La pirámide','Barcelona',150),(2,'La esfera','Barcelona',250),(3,'Césped','Madrid',300),(4,'Lago','Madrid',50),(5,'Celeste','Madrid',100),(6,'Multiusos','Valencia',100),(7,'The Beat Venue','Sevilla',250);
/*!40000 ALTER TABLE `Sales` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `UsuariGrups`
--

DROP TABLE IF EXISTS `UsuariGrups`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `UsuariGrups` (
  `idUsuari` int(11) NOT NULL,
  `idGrup` int(11) NOT NULL,
  PRIMARY KEY (`idUsuari`,`idGrup`),
  KEY `idGrup` (`idGrup`),
  CONSTRAINT `UsuariGrups_ibfk_1` FOREIGN KEY (`idUsuari`) REFERENCES `Usuaris` (`idUsuari`) ON DELETE CASCADE,
  CONSTRAINT `UsuariGrups_ibfk_2` FOREIGN KEY (`idGrup`) REFERENCES `GrupsMusicals` (`idGrup`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `UsuariGrups`
--

LOCK TABLES `UsuariGrups` WRITE;
/*!40000 ALTER TABLE `UsuariGrups` DISABLE KEYS */;
/*!40000 ALTER TABLE `UsuariGrups` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `UsuariRoles`
--

DROP TABLE IF EXISTS `UsuariRoles`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `UsuariRoles` (
  `idUsuari` int(11) NOT NULL,
  `idRol` int(11) NOT NULL,
  PRIMARY KEY (`idUsuari`,`idRol`),
  KEY `idRol` (`idRol`),
  CONSTRAINT `UsuariRoles_ibfk_1` FOREIGN KEY (`idUsuari`) REFERENCES `Usuaris` (`idUsuari`) ON DELETE CASCADE,
  CONSTRAINT `UsuariRoles_ibfk_2` FOREIGN KEY (`idRol`) REFERENCES `Roles` (`idRol`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `UsuariRoles`
--

LOCK TABLES `UsuariRoles` WRITE;
/*!40000 ALTER TABLE `UsuariRoles` DISABLE KEYS */;
/*!40000 ALTER TABLE `UsuariRoles` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Usuaris`
--

DROP TABLE IF EXISTS `Usuaris`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Usuaris` (
  `idUsuari` int(11) NOT NULL AUTO_INCREMENT,
  `nom` varchar(50) DEFAULT NULL,
  `cognom` varchar(50) DEFAULT NULL,
  `email` varchar(100) DEFAULT NULL,
  `contrasenya` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`idUsuari`),
  UNIQUE KEY `email` (`email`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Usuaris`
--

LOCK TABLES `Usuaris` WRITE;
/*!40000 ALTER TABLE `Usuaris` DISABLE KEYS */;
INSERT INTO `Usuaris` VALUES (1,'Eric','Costa','ec@email.com','eric_password'),(2,'Wei','Zhou','wei@email.com','wei_password'),(3,'Rubén','Gómez','ruben@email.com','ruben_password');
/*!40000 ALTER TABLE `Usuaris` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Valoracions`
--

DROP TABLE IF EXISTS `Valoracions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Valoracions` (
  `idValoracio` int(11) NOT NULL AUTO_INCREMENT,
  `idUsuariClient` int(11) DEFAULT NULL,
  `idConcert` int(11) DEFAULT NULL,
  `puntuacio` int(11) DEFAULT NULL CHECK (`puntuacio` between 1 and 5),
  `comentari` text DEFAULT NULL,
  `data` date DEFAULT NULL,
  PRIMARY KEY (`idValoracio`),
  KEY `idUsuariClient` (`idUsuariClient`),
  KEY `idConcert` (`idConcert`),
  CONSTRAINT `Valoracions_ibfk_1` FOREIGN KEY (`idUsuariClient`) REFERENCES `Usuaris` (`idUsuari`) ON DELETE CASCADE,
  CONSTRAINT `Valoracions_ibfk_2` FOREIGN KEY (`idConcert`) REFERENCES `Concerts` (`idConcert`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Valoracions`
--

LOCK TABLES `Valoracions` WRITE;
/*!40000 ALTER TABLE `Valoracions` DISABLE KEYS */;
/*!40000 ALTER TABLE `Valoracions` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-04-06 20:24:57
