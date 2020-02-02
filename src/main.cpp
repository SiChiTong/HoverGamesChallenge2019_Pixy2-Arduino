//
// Created by iwait on 1/22/20.
// https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:hooking_up_pixy_to_a_microcontroller_-28like_an_arduino-29
//
#include <Arduino.h>
#include <Pixy2.h>

// Pixy object
Pixy2 pixy; //note: it uses pin#10-13 for SPI
#define LED_DETECT 9

void setup()
{
    // init serial
    Serial.begin(115200);
    Serial.print("Starting...\n");

    // init camera
    pixy.init();

    // init led out
    pinMode(LED_DETECT, OUTPUT);
    digitalWrite(LED_DETECT, LOW);
}

void loop()
{
    int i;
    // grab blocks!
    pixy.ccc.getBlocks();

    // If there are detect blocks, print them!
    if (pixy.ccc.numBlocks)
    {
        // LED ON
        digitalWrite(LED_DETECT, HIGH);

        Serial.print("Detected ");
        Serial.println(pixy.ccc.numBlocks); // 何個オブジェクト(Block)が見つかったか
        // out for each block
        for (i=0; i<pixy.ccc.numBlocks; i++)
        {
            /**
             * pixy.ccc.blocks[i].m_signature The signature number of the detected object (1-7 for normal signatures)
             * pixy.ccc.blocks[i].m_x The x location of the center of the detected object (0 to 316)
             * pixy.ccc.blocks[i].m_y The y location of the center of the detected object (0 to 208)
             * pixy.ccc.blocks[i].m_width The width of the detected object (1 to 316)
             * pixy.ccc.blocks[i].m_height The height of the detected object (1 to 208)
             * pixy.ccc.blocks[i].m_angle The angle of the object detected object if the detected object is a color code (-180 to 180).
             * pixy.ccc.blocks[i].m_index The tracking index of the block
             * pixy.ccc.blocks[i].m_age The number of frames the block has been tracked.
             * pixy.ccc.blocks[i].print() A member function that prints the detected object information to the serial port
             */
            Serial.print("  block ");
            Serial.print(i);
            Serial.print(": ");
            pixy.ccc.blocks[i].print(); // sig: 1 x: 303 y: 194 width: 26 height: 8 index: 134 age: 3
        }
    } else {
        // LED OFF
        digitalWrite(LED_DETECT, LOW);
    }
}

