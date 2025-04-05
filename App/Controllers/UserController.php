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
            session_start();
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
        $user = $this->userGateway->findByEmail($email);

        //var_dump($this->userGateway->verifyPassword($contrasenya, $user['contrasenya']), $contrasenya, $user['contrasenya']);
        //var_dump();
        //die();

        if ($user != NULL && $this->userGateway->verifyPassword($contrasenya, $user['contrasenya'])) {
            $_SESSION['status'] = true;
            //CUIDADO que he pasado la contraseña al frontend!!! hay que tratar los datos! Con un DTO por ejemplo!
            unset($user['contrasenya']);
            $_SESSION['user'] = $user;   //luego hay que recoger y tratar los datos
            header("Location: /dashboard");
            //exit();
        } else {
            echo "mail i contrasenya incorrecta";
            //podríamos pasar algún dato para mostrar un mensaje de contraseña incorrecta
            // header("Location: /login");
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


    public function showUser($id)
    {
        //esta plantilla no debería interesarnos ya que seguramente lo haremos con javascript, pero para probar cosas la mantenemos
        $user = $this->getUserById($id);

        if ($user) {
            echo "Usuario encontrado: <br>";
            echo "ID: " . $user['id'] . "<br>";
            echo "Nombre: " . $user['name'] . "<br>";
            echo "Correo: " . $user['email'] . "<br>";
        } else {
            echo "Usuario no encontrado.";
        }
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
    public function deleteUser($id)
    {
        // Aquí iría el código para eliminar al usuario desde la base de datos
        // Vamos a simularlo para la demostración
        $user = $this->getUserById($id);

        if ($user) {
            // Simulamos la eliminación del usuario
            echo "Usuario con ID $id eliminado exitosamente.";
        } else {
            echo "Usuario no encontrado.";
        }
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
