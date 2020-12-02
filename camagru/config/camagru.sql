
CREATE DATABASE IF NOT EXISTS `camagru` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `camagru`;

CREATE TABLE IF NOT EXISTS `img` (
  `id_img` int(11) NOT NULL AUTO_INCREMENT,
  `title` varchar(150) DEFAULT NULL,
  `path` varchar(300) NOT NULL,
  `date_img` datetime NOT NULL,
  `id_stage` int(11) NOT NULL,
  `id_user` int(11) NOT NULL,
  PRIMARY KEY (`id_img`),
  KEY `id_stage` (`id_stage`),
  KEY `id_user` (`id_user`)
) ENGINE=InnoDB AUTO_INCREMENT=226 DEFAULT CHARSET=utf8;

INSERT INTO `img` (`id_img`, `title`, `path`, `date_img`, `id_stage`, `id_user`) VALUES
(223, 'Fait le 2019-05-27 10:06:37, par marie', 'public/img/upload/eac02d2dd0277949db33cc594d269dd72.jpg', '2019-05-27 10:06:37', 1, 1),
(224, 'test pikachu !!', 'public/img/upload/eac02d2dd0277949db33cc594d269dd73.jpg', '2019-05-27 10:07:06', 6, 1),
(225, 'GOT star wars', 'public/img/upload/eac02d2dd0277949db33cc594d269dd74.jpg', '2019-05-27 10:08:10', 9, 1);

CREATE TABLE IF NOT EXISTS `liked` (
  `id_liked` int(11) NOT NULL AUTO_INCREMENT,
  `id_user` int(11) NOT NULL,
  `id_img` int(11) NOT NULL,
  PRIMARY KEY (`id_liked`),
  KEY `id_user` (`id_user`),
  KEY `liked_ibfk_1` (`id_img`)
) ENGINE=InnoDB AUTO_INCREMENT=18 DEFAULT CHARSET=utf8;

INSERT INTO `liked` (`id_liked`, `id_user`, `id_img`) VALUES
(16, 1, 225),
(17, 1, 223);

CREATE TABLE IF NOT EXISTS `post` (
  `id_post` int(11) NOT NULL AUTO_INCREMENT,
  `comment` varchar(400) NOT NULL,
  `date_post` date NOT NULL,
  `id_author` int(11) NOT NULL,
  `id_img` int(11) NOT NULL,
  PRIMARY KEY (`id_post`),
  KEY `id_author` (`id_author`),
  KEY `id_img` (`id_img`)
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8;

INSERT INTO `post` (`id_post`, `comment`, `date_post`, `id_author`, `id_img`) VALUES
(19, 'mouais !', '2019-05-27', 1, 224);

CREATE TABLE IF NOT EXISTS `stage` (
  `id_stage` int(11) NOT NULL AUTO_INCREMENT,
  `name_stage` varchar(100) NOT NULL,
  `path` varchar(300) NOT NULL,
  PRIMARY KEY (`id_stage`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;

INSERT INTO `stage` (`id_stage`, `name_stage`, `path`) VALUES
(1, 'rondoudou', 'public/img/montage/rondoudou.png'),
(2, 'rose', 'public/img/montage/rose.png'),
(3, 'carapuce', 'public/img/montage/carapuce.png'),
(4, 'chapeau cowboy', 'public/img/montage/cowboyhat.png'),
(5, 'dracaufeu', 'public/img/montage/dracaufeu.png'),
(6, 'pikachu', 'public/img/montage/pikachu.png'),
(7, 'chapeau pere noel', 'public/img/montage/santahat.png'),
(8, 'soucoupe', 'public/img/montage/soucoupe.png'),
(9, 'tie fighter', 'public/img/montage/tiefighter.png');

CREATE TABLE IF NOT EXISTS `user` (
  `id_user` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(200) NOT NULL,
  `email` varchar(255) DEFAULT NULL,
  `password` varchar(200) NOT NULL,
  `birthday` date DEFAULT NULL,
  `country` varchar(255) DEFAULT NULL,
  `city` varchar(255) DEFAULT NULL,
  `notification` int(11) NOT NULL,
  `validate` int(11) DEFAULT NULL,
  `token` varchar(200) NOT NULL,
  PRIMARY KEY (`id_user`)
) ENGINE=InnoDB AUTO_INCREMENT=45 DEFAULT CHARSET=utf8;

INSERT INTO `user` (`id_user`, `username`, `email`, `password`, `birthday`, `country`, `city`, `notification`, `validate`, `token`) VALUES
(1, 'marie', 'dufourqmarie2975@gmail.com', '6db8f4b54e3797481423c48cf27bc75039eb02597f3dfdf552ba42f70525232ca9628157017ba068afc3281f741cce962f8f2859a027999295761d4a8329c094', '1996-07-12', 'france', 'paris', 1, 1, 'f4c8e02f3cf4f6b8e7f7c1b3c72cbe191148be8b959bb284cd691c67d44156cb');

ALTER TABLE `img`
  ADD CONSTRAINT `img_ibfk_1` FOREIGN KEY (`id_stage`) REFERENCES `stage` (`id_stage`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `img_ibfk_2` FOREIGN KEY (`id_user`) REFERENCES `user` (`id_user`) ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `liked`
  ADD CONSTRAINT `liked_ibfk_1` FOREIGN KEY (`id_img`) REFERENCES `img` (`id_img`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `liked_ibfk_2` FOREIGN KEY (`id_user`) REFERENCES `user` (`id_user`) ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE `post`
  ADD CONSTRAINT `post_ibfk_1` FOREIGN KEY (`id_author`) REFERENCES `user` (`id_user`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `post_ibfk_2` FOREIGN KEY (`id_img`) REFERENCES `img` (`id_img`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;
