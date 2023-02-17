-- phpMyAdmin SQL Dump
-- version 4.9.2
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le :  ven. 17 fév. 2023 à 11:16
-- Version du serveur :  10.4.10-MariaDB
-- Version de PHP :  7.4.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `garage`
--

-- --------------------------------------------------------

--
-- Structure de la table `factures`
--

DROP TABLE IF EXISTS `factures`;
CREATE TABLE IF NOT EXISTS `factures` (
  `idFact` int(110) NOT NULL AUTO_INCREMENT,
  `idV` varchar(110) NOT NULL,
  `prix` int(110) NOT NULL,
  PRIMARY KEY (`idFact`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `factures`
--

INSERT INTO `factures` (`idFact`, `idV`, `prix`) VALUES
(1, '1938HTK', 1000),
(2, '132GE', 1500);

-- --------------------------------------------------------

--
-- Structure de la table `placeparking`
--

DROP TABLE IF EXISTS `placeparking`;
CREATE TABLE IF NOT EXISTS `placeparking` (
  `nomP` varchar(110) NOT NULL,
  `nbPlaceMoto` int(110) NOT NULL,
  `nbPlaceVoiture` int(110) NOT NULL,
  `nbPlaceCamion` int(110) NOT NULL,
  PRIMARY KEY (`nomP`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `placeparking`
--

INSERT INTO `placeparking` (`nomP`, `nbPlaceMoto`, `nbPlaceVoiture`, `nbPlaceCamion`) VALUES
('AUTOPACK', 12, 4, 10);

-- --------------------------------------------------------

--
-- Structure de la table `vehicules`
--

DROP TABLE IF EXISTS `vehicules`;
CREATE TABLE IF NOT EXISTS `vehicules` (
  `idV` varchar(110) NOT NULL,
  `Type` varchar(110) NOT NULL,
  `dureeStationnement` time NOT NULL,
  `estBienplacé` tinyint(1) NOT NULL,
  PRIMARY KEY (`idV`),
  UNIQUE KEY `idV` (`idV`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `vehicules`
--

INSERT INTO `vehicules` (`idV`, `Type`, `dureeStationnement`, `estBienplacé`) VALUES
('132GE', 'Voiture', '03:06:22', 0),
('1389HT', 'Voiture', '01:31:11', 1),
('1938HTK', 'Moto', '05:10:00', 0),
('10039H', 'Moto', '00:25:12', 0);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
