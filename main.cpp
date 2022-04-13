#include "mbed.h" //p2

Thread t;
Thread Genwave;

float i;
EventQueue queue;
// main() runs in its own thread in the OS
AnalogOut Aout(PA_4);

void print()
{
    printf("endperiod");
}

void DA()
{
    while(1)
    {
        for (i = 0.0f; i <= 3.0f; i += 0.06f)
        {
            Aout = tanh(i);
            ThisThread::sleep_for(1ms);
        }
        for (i = 3.0f; i <= 6.0f; i += 0.06f)
        {
            Aout =  (1 - tanh(i - 3));
            ThisThread::sleep_for(1ms);
        }
        //queue.call(print);
    }
}

int main()
{
    t.start(callback(&queue, &EventQueue::dispatch_forever));

    Genwave.start(DA);
}

