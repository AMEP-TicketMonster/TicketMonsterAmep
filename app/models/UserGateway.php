<?php
require_once __DIR__ . "/../../config/config.php"; // Cambiamos a config.php para usar Database

class UserGateway {
    private $pdo;
    private $id;
    private $email;
    private $password;

    public function __construct() {
        $this->pdo = Database::getInstance(); // Usamos el Singleton para la conexión
    }

    // Cargar un usuario por su email
    public function findByEmail($email) {
        $stmt = $this->pdo->prepare("SELECT * FROM Usuaris WHERE email = ?");
        $stmt->execute([$email]);
        $user = $stmt->fetch();

        if ($user) {
            $this->id = $user["idUsuari"];
            $this->email = $user["email"];
            $this->password = $user["contrasenya"];
        }
        //Esto que parece un poco raro es para devolver el usuario lo tenemos que coger con pinzas porque no es la forma más optima
        return $user;
    }

    // Verificar la contraseña
    public function verifyPassword($password) {
        //echo"<br>esto es verifyPassword";
        //return password_verify($password, $this->password);
        return ($password == $this->password);
    }

    // Obtener datos del usuario autenticado
    public function getId() {
        return $this->id;
    }

    public function getEmail() {
        return $this->email;
    }
}
?>
