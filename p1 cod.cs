// Variáveis com as portas digitais do sensor e do motor
int sensor = 6;
int motor = 7;

// Variáveis com os níveis mine  max de água (em cm)
long min = 5;
long max = 50;

// Variável com a altura do sensor em relação ao tanque (em cm)
long distanciaSensor = 60;

// Variável para o estado do motor
bool ligado = false;

void setup()
{
    pinMode(motor, OUTPUT); // Motor (para a bomba)
    Serial.begin(9600);
}

// Função para medir a distância dos sensores
long measure(int pin)
{
    // Variáveis para duração e dstância do Ping dos sensores
    long cm, duration;

    // Aciona um pulso
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    delayMicroseconds(2);
    digitalWrite(pin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pin, LOW);

    // O sensor escuta o pulso
    pinMode(pin, INPUT);
    duration = pulseIn(pin, HIGH);

    // Converte a distância para cm's e retorna o nivel da água no tanque
    // 29 e 2 são constantes (com relação à velocidade do som, etc)
    cm = distanciaSensor - (duration / 29 / 2);
    Serial.print(cm);
    Serial.println("cm");
    return cm;
}

void loop()
{
    // Testa se a bomba já está ligada
    if (ligado == true)
    {
        // Bomba ligada (reservatório enchendo)

        // Realiza o teste no sensor de nivel maximo
        if (measure(sensor) >= max)
        {
            // Quando a distância for menor que 10 cm's
            // desliga o motor

            digitalWrite(motor, LOW);
            ligado = false;
        }
    }
    else
    {
        // Bomba desligada (tanque envaziando)

        // Realiza o teste no sensor de nivel minimo
        if (measure(sensor) <= min)
        {
            // Quando a distância for menor que 10 cm's
            // Água acabando
            // liga o motor

            digitalWrite(motor, HIGH);
            ligado = true;
        }
    }
}
