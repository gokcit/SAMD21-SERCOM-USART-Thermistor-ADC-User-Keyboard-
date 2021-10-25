# SAMD21-SERCOM-USART-Thermistor-ADC-User-Keyboard-
> A Harmony 3 Project where User requests the temperature with Keyboard Input or push button
> Future: Client requesting temperature via I2C

## Hardware Stack
SAMD21 Xplained Pro (SAMD21J18A)
A thermistor
## Peripherals
ADC, USART, push button
Future: DMA, SPI and I2C

## Program Output
![alt text](https://github.com/gokcit/SMT_Board_Training/blob/master/schematic.png)
## PCB Layout
![alt text](https://github.com/gokcit/SMT_Board_Training/blob/master/pcb%202d.png)
## 3D View
![alt text](https://github.com/gokcit/SMT_Board_Training/blob/master/pcb%203d.png)

## Installation


#### GitHub Desktop (simple user interface)
https://desktop.github.com/

#### git Bash
https://git-scm.com/downloads

### Scenario 1: I share my code with a customer

Windows:

#### Creating A Local Repository

##### 1. Create a new folder. The name and the location of this folder is up to you. Below is an example.
```sh
$ cd C:\Users\<YOUR_BADGE_NUMBER>
```
```sh
$ mkdir GitHub
$ cd GitHub
```
##### 2. Paste your project folder in GitHub Folder.

#### 3. Synchronize your local repository with the remote repository.
Link: https://docs.github.com/en/github/importing-your-projects-to-github/importing-source-code-to-github/adding-an-existing-project-to-github-using-the-command-line

###### Helpful Commands (open git Bash)
```sh
$ git init -b master
$ git status
$ git add .
$ git status
$ git commit -m "First commit"
$ git remote add origin <REMOTE_URL>
$ git push origin master
```
### Scenario 2: Customer shared their code with me on GitHub.

_For more examples and usage, please refer to the [Wiki][wiki]._

## Development setup

Describe how to install all development dependencies and how to run an automated test-suite of some kind. Potentially do this for multiple platforms.

```sh
make install
npm test
```

## Contributing

1. Fork it (<https://github.com/yourname/yourproject/fork>)
2. Create your feature branch (`git checkout -b feature/fooBar`)
3. Commit your changes (`git commit -am 'Add some fooBar'`)
4. Push to the branch (`git push origin feature/fooBar`)
5. Create a new Pull Request

<!-- Markdown link & img dfn's -->
[npm-image]: https://img.shields.io/npm/v/datadog-metrics.svg?style=flat-square
[npm-url]: https://npmjs.org/package/datadog-metrics
[npm-downloads]: https://img.shields.io/npm/dm/datadog-metrics.svg?style=flat-square
[travis-image]: https://img.shields.io/travis/dbader/node-datadog-metrics/master.svg?style=flat-square
[travis-url]: https://travis-ci.org/dbader/node-datadog-metrics
[wiki]: https://github.com/yourname/yourproject/wiki
