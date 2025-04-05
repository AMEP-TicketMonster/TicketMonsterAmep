<?php

namespace App\Controllers;

use App\Models\UserGateway;
use Core\Route;
use Core\Auth;
use Core\Session;

class UserController
{
    private $userGateway;

    public function __construct()
    {
        $this->userGateway = new UserGateway();
        if (session_status() === PHP_SESSION_NONE) {
            Session::sessionStart("ticketmonster_session");
        }
    }

    public function login()
    {
        $email = trim($_POST["email"]);
        $contrasenya = trim($_POST["password"]);

        if (empty($email) || empty($contrasenya)) {
            echo "Error: Todos los campos son obligatorios.";
            return;
        }

        // Obtener el usuario por email
        $user = $this->userGateway->getByEmail($email);

        //var_dump($this->userGateway->verifyPassword($contrasenya, $user['contrasenya']), $contrasenya, $user['contrasenya']);
        //var_dump();
        //die();

        if ($user != NULL && $this->userGateway->verifyPassword($contrasenya, $user['contrasenya'])) {
            $_SESSION['status'] = true;
            unset($user['contrasenya']);                //CUIDADO que he pasado la contraseña al frontend!!! hay que tratar los datos! Con un DTO por ejemplo!
            $_SESSION['user'] = $user;   //luego hay que recoger y tratar los datos
            header("Location: /dashboard");
            //exit();
        } else {
            $_SESSION['bad_login_data'] = true;
            header("Location: /login");
        }
    }
    public function register()
    {
        //to do...
        /*
        if ($_SERVER["REQUEST_METHOD"] === "POST") {
            $email = trim($_POST["email"]);
            $contrasenya = trim($_POST["password"]);

            if (empty($email) || empty($contrasenya)) {
                echo "Error: Todos los campos son obligatorios.";
                return;
            }

            // Obtener el usuario por email
            $user = $this->userGateway->findByEmail($email);

            //var_dump($this->userGateway->verifyPassword($contrasenya, $user['contrasenya']), $contrasenya, $user['contrasenya']);
            //var_dump();
            //die();

            if ($user && $this->userGateway->verifyPassword($contrasenya, $user['password'])) {
                $_SESSION["idUsuari"] = $user['idUsuari'];
                $_SESSION["email"] = $user['email'];
                //CUIDADO que he pasado la contraseña al frontend!!! hay que tratar los datos!
                $datos_json = json_encode($user);

                // Redirigir a otra página con los datos
                $_SESSION['user'] = ($datos_json);   //luego hay que recoger y tratar los datos
                $_SESSION['session_status'] = json_encode(true); //indico que la sessión está iniciada
                header("Location: /dashboard");
                exit();
            } else {
                echo "mail i contrasenya incorrecta";
            }
        }
            */
    }

    public function logout()
    {
        Session::closeSession();
        //session_destroy();
        header("Location: /login");
        exit();
    }



    public function createUser($name, $email, $password)
    {
        //poner el código del insert

        if ($this->isValidEmail($email)) {
            $hashedPassword = password_hash($password, PASSWORD_DEFAULT); // Encriptar la contraseña
            // Simular la creación de un nuevo usuario
            echo "Nuevo usuario creado: <br>";
            echo "Nombre: " . $name . "<br>";
            echo "Correo: " . $email . "<br>";
            // En un entorno real, deberías guardar estos datos en una base de datos.
        } else {
            echo "Correo electrónico no válido.";
        }
    }

    // Eliminar un usuario por ID
    public function delete($id)
    {
        //antes de hacer la eliminación habrá que revisar a cuantas tablas afecta i ver si se puede hacer o afectaría a la lógica del programa
        $user = $this->userGateway->getByUserId($id);
        if ($user) {
            $this->userGateway->delete($id);
        }
        //borrar la sesión para que no se pueda acceder a las rutas.
        Session::closeSession();
    }

    // Función auxiliar para obtener un usuario por su ID (simulada con un array)
    private function getUserById($id)
    {
        // Simulación de una base de datos de usuarios
        $users = [
            1 => ['id' => 1, 'name' => 'Juan Pérez', 'email' => 'juan@ejemplo.com'],
            2 => ['id' => 2, 'name' => 'Ana García', 'email' => 'ana@ejemplo.com']
        ];

        return isset($users[$id]) ? $users[$id] : null;
    }

    // Función para validar el correo electrónico
    private function isValidEmail($email)
    {
        return filter_var($email, FILTER_VALIDATE_EMAIL) !== false;
    }
}
