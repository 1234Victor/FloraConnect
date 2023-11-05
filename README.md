# FloraConnect
## Inspiration

Our inspiration for FloraConnect sprouted from a desire to bridge the gap between technology and nature. We wanted to create a unique plant "pet" that would not only monitor humidity but also serve as an alarm clock, and even have the ability to interact with its owner. Our goal was to offer a refreshing and interactive way for people to connect with their plants while providing essential care.

## What it does

FloraConnect is a multifunctional plant companion. It utilizes Arduino, Bluetooth signals, buzzers, hex displays, humidity sensors, and more to track soil humidity and set alarms through a mobile app. When an alarm triggers, a buzzer reminds the owner to water the plant, and the plant itself delivers encouraging messages. The hex display shows the time and a charming facial expression on an LCD screen, enhancing the interactive experience. In addition, the plant can also interact with human, it would "speak" if someone get close to them or if some one touch them.

## How we built it

We constructed FloraConnect using an Arduino set and Arduino IDE, integrating a variety of hardware components such as Bluetooth signals, buzzers, humidity sensors, and ultrasonic sensors. The mobile app was developed using React Native and JavaScript, providing users with a user-friendly interface for setting alarms and monitoring their plant's well-being.

## Challenges we ran into

Throughout the project, we faced several hurdles, including limited pins and memory access on the Arduino Uno. Our aim was to incorporate various types of messages, but we struggled to save large MP3 files due to memory constraints. Additionally, we initially aimed to unify the functions on a single Arduino board, but ultimately required two boards to accommodate the complexity of the system. Integrating loops within the Arduino Uno also presented difficulties. While the individual functions worked smoothly in isolation, merging them and printing information simultaneously led to complications in managing multiple displays at once.

## Accomplishments that we're proud of

We're immensely proud of successfully creating FloraConnect, a one-of-a-kind plant companion that combines technology and nature. Achieving a seamless interaction between the plant and the app, along with the charming facial expressions, were significant accomplishments.

## What we learned

Developing FloraConnect taught us valuable lessons in hardware integration, coding, and creating an interactive user experience. We also gained a deeper appreciation for the importance of nurturing our connection with nature.

## What's next for FloraConnect

Our future plans for FloraConnect involve integrating an API directly into the Arduino board, enabling users to engage in direct conversations with their plant companion. This exciting development will further enhance the interactivity and personal connection between individuals and their beloved plant "pet."
