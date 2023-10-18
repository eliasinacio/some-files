### Ambiente de Desenvolvimento (Linux)

Dependências importantes:

**Terminal**

- `nvm` versões mais usadas:
  - `node 10`
    - `oracle-commerce-cli`
  - `node 14`
  - `node 16`
- `yarn`
- `vtex cli`
- `docker engine`



**Android studio**

documentação: https://reactnative.dev/docs/environment-setup?os=linux

-  `Android SDK 31`

Instalação do Java e Android Studio no Ubuntu



**Outros aplicativos**

- `Postman`

- `Docker`

- `AnyDesk`



### Dicas para devs

1. Muito cuidado ao criar coisas por endpoint elas não podem ser apagadas.
2. Crie sempre listPrices por endpoint, por interface eles são criados mas ficam invisíveis.
3. Seus melhores amigos são o google e o chat gpt.



##### OCC Classic

1. Usar Node 10. 
2. Baixar DesignCodeUtility no admin do projeto.



### Git

commit no passado
`git commit --date="10 day ago" -m "Your commit message" `

remove as branchs que não existem mais no remote

`git fetch --prune`

### React Native

##### iOS - Como gerar build para testar no Lambdatest 

1. terminal
   `npx react-native bundle --entry-file index.js --platform ios --dev false --bundle-output ios/main.jsbundle --assets-dest ios`
2. Xcode
   product > Scheme > Edit Schemes > build Configuration > Release
   product > Scheme > Manage Schemes > nome do projeto > (mundar 'Container' para workspace )
   product > clean build
   product > build
3. compactar pasta gerada do build
   App > App > Products > App - [Open in Finder]
4. Zip

#### iOS - Atualizar main.jsbundle

```bash
npx react-native bundle --entry-file index.js --platform ios --dev false --bundle-output ios/main.jsbundle --assets-dest ios
```



##### Android - Gerar apk pelo terminal

1. `npx react-native bundle --platform android --dev false --entry-file index.js --verbose --bundle-output android/app/src/main/assets/index.android.bundle --assets-dest android/app/src/main/res`
2. ``cd android`
3. `./gradlew assembleDebug` ou `./gradlew assembleRelease`

Linux - Android Studio - android

`android-studio-2021.2.1`

```ext {
// build.gradle
ext {
        buildToolsVersion = "34.00"
        minSdkVersion = 21
        compileSdkVersion = 33
        targetSdkVersion = 33
        kotlinVersion = "1.6.0"
    }
   
// gradle > wrapper

distributionUrl=https\://services.gradle.org/distributions/gradle-6.5-all.zip

```

No android studio baixado apenas SDK 33





