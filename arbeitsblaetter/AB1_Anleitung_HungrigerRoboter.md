# 🤖 Hungriger Roboter – AB1: Anleitung & Aufgabenstellung

## Situation

Der Hungrige Roboter frisst alles, was man ihm vor den Mund hält. Im Inneren steckt ein **Arduino**, ein **Sensor** und ein **Servo‑Motor**, der den Mund öffnet und schließt.

## Aufgaben

1. Benenne die wichtigsten Teile und ihre Funktion.
2. Überlege, wo der Sensor sitzen muss.
3. Erstelle eine Systemskizze: Sensor → Arduino → Servo.
4. Formuliere einen Pseudocode für das Verhalten.

## Pseudocode-Idee

```text
Wiederhole ständig:
   miss Abstand
   wenn Abstand < ... cm:
       Mund öffnen
       kurz warten
       Mund schließen
   sonst:
       Mund geschlossen lassen
```
