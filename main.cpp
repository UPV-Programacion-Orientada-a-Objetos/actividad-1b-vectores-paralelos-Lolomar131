#include <iostream>
#include <limits>

int main()
{
   // Creado por José Oswaldo Tienda Mendoza

   // Creación de los Arreglos

   /* Con valores iniciales de 5 para despues ir agregando o eliminando
      productos a peticion del usuario. */

   int codigo_producto[100] = {
       100,
       101,
       102,
       103,
       104};

   std::string nombre_producto[100] = {
       "Taladro",
       "Martillo",
       "Candados",
       "Grifos",
       "Tornillos"};

   int cantidad_stock[100] = {
       20,
       15,
       40,
       10,
       200};

   float precio_unitario[100] = {
       900,
       300,
       200,
       300,
       10};

   // Variables auxiliares 
   bool bandera = false;
   int opt = 0;
   int codigo = 0;
   int tamaño;
   int nuevo_stock = 0;

   int aux = 0;

   // Variables para el apartado del producto más caro
   float prodcuto_mas_caro = 0;
   int indice_caro = -1;

   // Mensaje de beinvenida que solo se muestra al iniciar el proyecto
   std::cout << "Bienvenido al Sistemma de Inentario de -El martillo- \n \n";

   //do while encargado de mostrar de nuevo el menu 
   do
   {

      codigo = 0;
      // Opciones del menu mismas con las que el usuario podra realizar acciones en el programa

      std::cout << "\n Ferreteria - El martillo -\n";
      std::cout << "-----------------------   \n";
      std::cout << "       M    E    N    U       \n";
      std::cout << "    Seleccione una opción:   \n";
      std::cout << "-----------------------  \n";
      std::cout << "1.- Consultar un producto \n";
      std::cout << "2.- Actualizar el inventario\n";
      std::cout << "3.- Generar el reporte completo\n";
      std::cout << "4.- Encontrar el producto más caro\n";
      std::cout << "5.- Salir \n\n\n";
      std::cin >> opt;

      //Validaciones

      if (std::cin.fail())//.fail() es una funcion que nos devuelve true en caso de que mande al fallo en este caso pedimos un numero y si llega a ingresar una letra entra la función
      {
         std::cout << "Entrada invalida. Por favor, ingrese un numero.\n";
         std::cin.clear();//Reinicia el estado de cin
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Descarta los valores que el usuario ingreso de forma incorrecta 
         opt = 0;
      }

      switch (opt)
      {
      case 1:
         // Apartado de consultar un producto
         std::cout << "Apartado de consultar un producto\n";
         std::cout << "---------------------------------\n";
         std::cout << "Ingrese el código del producto a consultar:\n";
         std::cin >> codigo;
 
         //Validaciones iguales que arriba explicacion en linea 78
         if (std::cin.fail())
         {
             std::cin.clear();
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         } else {

        // Si la entrada es un número, se realiza la búsqueda
        for (int i = 0; i < 100; i++) 
        {
            if (codigo == codigo_producto[i]) 
            {
               
                std::cout << "Informacion del Producto \n";
                std::cout << "Codigo: " << codigo_producto[i] << std::endl;
                std::cout << "Nombre: " << nombre_producto[i] << std::endl;
                std::cout << "Cantidad en stock: " << cantidad_stock[i] << std::endl;
                std::cout << "Precio unitario: " << precio_unitario[i] << std::endl;
                break;//En caso de que si encuentre el valor con el brake se rompe en ciclo
            }
        }
    }
         

         // tamaño = sizeof(codigo_producto) / sizeof(codigo_producto[0]);    

         break;

      case 2:
         // Apartado de actualizar el inventario
         std::cout << "Apartado de actualizar el inventario \n";
         std::cout << "------------------------------------ \n";
         std::cout << "Ingrese el codigo del producto que desee actualizar \n";
         std::cin >> codigo;


         //Validaciones
            if (std::cin.fail()) {
        std::cout << "Entrada invalida. Por favor, ingrese un numero.\n";
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        break; // Salir del caso para que el menu se repita
    }

        for (int i = 0; i < 100; i++) {
        if (codigo == codigo_producto[i]) {
         
            std::cout << "Codigo: " << codigo_producto[i] << std::endl;
            std::cout << "Nombre: " << nombre_producto[i] << std::endl;
            std::cout << "Cantidad actual en el stock: " << cantidad_stock[i] << std::endl;
            std::cout << "Ingresa la cantidad para actualizar el stock: \n";
            
            int nuevo_stock; // Variable local para el nuevo stock
            std::cin >> nuevo_stock;

            // Validacion de la entrada del nuevo stock
            if (std::cin.fail()) {
                std::cout << "Entrada invalida. Por favor, ingrese un numero.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if ((cantidad_stock[i] + nuevo_stock) < 0) {
                std::cout << "Error: La cantidad despues de ingresar no puede ser menor a 0.\n";
            } else {
                cantidad_stock[i] += nuevo_stock;
                std::cout << "Cantidad del stock actualizada correctamente. \n";
                std::cout << "Nueva cantidad en stock: " << cantidad_stock[i] << std::endl;
            }
            break; // Salir del bucle una vez que se encuentra el producto
        }
    }
         break;

      case 3:
         // Apartado generar reporte completo
         std::cout << "--- Reporte de Inventario ---\n";
         std::cout << "Codigo | Nombre      | Stock | Precio\n";
         std::cout << "--------------------------------------\n";

      

         for (int i = 0; i < 100; ++i)
         {

            std::cout << codigo_producto[i] << "    ";
            std::cout << "| " << nombre_producto[i];
            std::cout << "\t| " << cantidad_stock[i] << "    ";
            std::cout << "| $" << precio_unitario[i] << std::endl;
         }

         std::cout << "--------------------------------------\n";
         std::cout << "--- Fin del Reporte ---\n";
         break;

      case 4:
         // Apartado encontrar el producto más caro

         std::cout << "Apartado del producto más caro \n";

         //Ciclo para recorrer el arreglo
         for (int i = 0; i < 100; i++)
         {
            //Se verifica la posición iniciar del arreglo y si es mayor que el producto mas caro se se almacena en producto mas caro

            if (precio_unitario[i] > prodcuto_mas_caro)
            {
               prodcuto_mas_caro = precio_unitario[i];//Aqui es donde se cambia el valor
               indice_caro = i;//Se guarda el indice en el que se encontro el mayos para imprimir el nombre y el precio 
            }
         }
         std::cout << "El producto más caro es: \n";
         std::cout << "Nombre: \t" << nombre_producto[indice_caro] << std::endl;
         std::cout << "Precio: \t" << precio_unitario[indice_caro] << std::endl;

         break;

      case 5:
         // Apartado de salir
         std::cout << "Hasta pronto chaval , Que tengas lindo dia Bendiciones \n"; //Mensaje de salida

         break;

      default:
         std::cout << "Opcion invalida. Favor de ingresar una opcion valida";
         break;
      }

   } while (opt != 5);

   return 0;
}
