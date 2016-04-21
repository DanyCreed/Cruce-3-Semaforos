
// Se declara un variable para el boton.
const int button = 13;

void setup() {
  // Con un ciclo for activamos los pines del 2 al 10 como salidas
  for (int pin = 2; pin <= 10; pin++) {
    pinMode(pin, OUTPUT);
  }
  // El pin del boton lo ponemos como entrada
  pinMode(button, INPUT);
}

// Funcion para el primer semaforo y sus cambios de luces.
void semaforouno() {
  digitalWrite(2, HIGH);
  int count = 0;
  while (count < 30) {
    // El ciclo esta en espera mientras el boton no es presionado
    if (digitalRead(button) == true) {
      break;
    }
    count++;
    delay(200);
  }
  digitalWrite(2, HIGH); //pin 2 sera luz verde
  delay(3000);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);//pin tres sera luz amarilla
  delay(2500);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH); //pin cuatro sera luz roja
  digitalWrite(7, LOW);//apagamos luz roja del semaforo dos.
  digitalWrite(10, HIGH);//encendemos luz roja de semaforo tres.
  // Mandamos a llamar al otro semaforo
  semaforodos();
}

// Funcion para el segundo semaforo y sus cambios de estado
void semaforodos() {
  digitalWrite(5, HIGH);
  int count = 0;
  while (count < 30) {
    if (digitalRead(button) == true) {
      break;
    }
    count++;
    delay(200);
  }
  digitalWrite(5, HIGH); //luz verde del segundo semaforo
  delay(3000);
  digitalWrite(5, LOW);
  delay(500);
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(5, LOW);
  delay(500);
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(5, LOW);
  delay(500);
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(5, LOW);
  delay(500);
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);//luz amarilla del segundo semaforo.
  delay(2500);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);//encendemos luz roja del segundo semaforo
  digitalWrite(10, LOW);//apagamos lus roja del tercer semaforo
  digitalWrite(4, HIGH);//encendemos luz roja del primer semaforo.
  // Mandamos a llamar al tercer semaforo
  semaforotres();
}

void semaforotres() {
  digitalWrite(8, HIGH);
  int count = 0;
  while (count < 30) {
    if (digitalRead(button) == true) {
      break;
    }
    count++;
    delay(200);
  }
  digitalWrite(8, HIGH);//encendemos luz verde del tercer semaforo
  delay(3000);
  digitalWrite(8, LOW);
  delay(500);
  digitalWrite(8, HIGH);
  delay(500);
  digitalWrite(8, LOW);
  delay(500);
  digitalWrite(8, HIGH);
  delay(500);
  digitalWrite(8, LOW);
  delay(500);
  digitalWrite(8, HIGH);
  delay(500);
  digitalWrite(8, LOW);
  delay(500);
  digitalWrite(8, HIGH);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);//encendemos luz amarilla del tercer semaforo 
  delay(2500);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);//encendemos luz roja de semaforo tres
  digitalWrite(4, LOW);//apagamos luz roja del primer semaforo
  digitalWrite(7, HIGH);//encendemos luz roja del segundo semaforo.
  //repetimos mandando a llamar el primer semaforo
  semaforouno();
}

// Iniciamos nuestro semaforo
void loop() {
  // Cambiamos el estado de todos los leds para
  // que esten apagados todos al inicio
  for (int pin = 2; pin <= 10; pin++) {
    digitalWrite(pin, LOW);
  }
  // Prendemos el verde de un semaforo y el
  // rojo del otro semaforo
  digitalWrite(2, HIGH);
  digitalWrite(10, HIGH);
  // Iniciamos el primer semaforo
  semaforouno();
}
