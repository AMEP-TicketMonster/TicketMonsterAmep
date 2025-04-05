<?php

namespace Core;

use App\Controllers\UserController;
use App\Core\Auth;

class Route
{
    public static function route()
    {
        $requestUri = trim(parse_url($_SERVER['REQUEST_URI'], PHP_URL_PATH), '/');
        $requestMethod = $_SERVER['REQUEST_METHOD'];  // Obtener el método HTTP (GET, POST, etc.)

        $publicRoutes = [
            '',
            'login',
            'register'
        ];

        $privateRoutes = [
            'conciertos',
            'salas',
            'dashboard',
            'logout'
        ];


        if (!isset($_SESSION['status']) && in_array($requestUri, $privateRoutes)) {
            Auth::accessDashboard(); // Redirige al login si no está logueado
            // exit();
        }

        if (isset($_SESSION['status']) && in_array($requestUri, $publicRoutes)) {
            Auth::accessLogin(); // Redirige si ya está logueado
            exit();
        }



        // Rutas válidas y sus archivos de vista
        $routes = [
            ''           => 'home.php',     // Página de llegada
            'login'      => 'users/login.php',
            'register'   => 'users/register.php',
            'dashboard'  => 'users/dashboard.php',
            'conciertos' => 'conciertos.php',
            'salas'      => 'salas.php'
        ];

        if ($requestMethod === 'GET') {
            //Para el caso de las vistas
            if (array_key_exists($requestUri, $routes)) {
                $file = __DIR__ . "/../Views/" . $routes[$requestUri];

                if (is_readable($file)) {
                    return $file;
                } else {
                    return __DIR__ . '/../Views/404.php'; // Si el archivo no existe, mostrar 404
                }
            }
            if ($requestUri == 'logout') {
                $controller = new UserController();
                $controller->logout();
                exit();  
            }
        } else if ($requestMethod === 'POST') {
            if ($requestUri === 'login') {
                // Llamamos al método login() del controlador UserController
                $controller = new UserController();
                $controller->login();
                exit();  // Detenemos la ejecución después de manejar la solicitud
            }

            if ($requestUri === 'register') {
                // Llamamos al método register() del controlador UserController
                $controller = new UserController();
                $controller->register(); // Asegúrate de tener el método en tu UserController
                exit();
            }
        }

        return __DIR__ . '/../Views/404.php'; // Si la ruta no está en la lista, mostrar 404


    }
}
