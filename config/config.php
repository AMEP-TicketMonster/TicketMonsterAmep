<?php
class Database {
    private static $instance = null;
    private $connection;

    // Configuración de la base de datos
    private $host = "localhost";  // Cambia si usas otro host
    private $dbname = "amep";  // Cambia al nombre de tu base de datos
    private $user = "ruben";       // Cambia según tu usuario de BD
    private $password = "Debian";       // Cambia según tu contraseña

    // Constructor privado para evitar la creación de más de una instancia
    private function __construct() {
        try {
            $this->connection = new PDO("mysql:host=$this->host;dbname=$this->dbname", 
                $this->user, $this->password, [
                    PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
                    PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC
                ]);
        } catch (PDOException $e) {
            //enviar mensaje a una vista
            die("Error de conexión: " . $e->getMessage());
        }
    }

    // Método para obtener la instancia de la conexión
    public static function getInstance() {
        if (!self::$instance) {
            self::$instance = new Database();
        }
        return self::$instance->connection;
    }
}
?>
