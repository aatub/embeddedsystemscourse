*** Settings ***
Library           SerialLibrary

Suite Setup       Connect Serial
Suite Teardown    Disconnect Serial

*** Variables ***
${PORT}           COM15
${BAUDRATE}       115200

*** Keywords ***
Connect Serial
    Add Port    ${PORT}    baudrate=${BAUDRATE}    timeout=2
    Open Port   ${PORT}

Disconnect Serial
    Close Port  ${PORT}

*** Test Cases ***
Valid Time String
    Write Data        000120\r\n
    ${res}=           Read Until    \n
    Should Contain    ${res}        80

Invalid Time String
    Write Data        001067\r\n
    ${res}=           Read Until    \n
    Should Contain    ${res}        -1
