# 🔐 Cofre Biométrico — Segurança Mobile e Biometria em Flutter

Aplicativo desenvolvido para o **Workshop Técnico** da disciplina **Laboratório de Desenvolvimento para Dispositivos Móveis** (PUC Minas — Prof. Cristiano Rodrigues).

O projeto demonstra na prática como implementar **autenticação biométrica local**, **armazenamento criptografado de segredos** e **mecanismos contra força bruta** em Flutter utilizando exclusivamente os pacotes oficiais recomendados.

---

## 👥 Integrantes do Grupo

* Rafael Assis Carvalho Lacerda
* Bernardo Barbosa Heronville
* Gabriel Assis Carvalho Lacerda
* Pedro Henrique Lopes de Melo e 
* Rafael Portilho de Andrade

---

## 🎯 Funcionalidades Demonstradas

* **Diagnóstico de Hardware (`local_auth`):** Verifica em tempo real se o dispositivo possui sensor biométrico, se há bloqueio/PIN configurado no sistema e quais modalidades estão ativas (`Digital`, `Facial`, `Forte / Class 3` ou `Fraca / Class 2`).
* **Desbloqueio de Sessão Local:** Libera o acesso local a um token de sessão previamente autenticado (`SESSAO_AUTENTICADA_#9842`), suportando biometria e o PIN/Padrão nativo do aparelho (`biometricOnly: false`).
* **Dupla Camada de Proteção (Ação Sensível):** Exige uma nova confirmação biométrica (ou senha) para autorizar uma transferência Pix simulada de `R$ 500,00`.
* **Fallback e Alteração de Senha do App:** Caso o aparelho não possua biometria cadastrada ou o usuário opte por não utilizá-la, o app oferece autenticação via senha própria salva de forma criptografada (**senha padrão inicial: `1234`**), permitindo também cadastrar uma nova senha na tela desbloqueada.
* **Bloqueio Temporário Persistente:** Após **3 falhas consecutivas** (na biometria ou na senha), o acesso é bloqueado por **30 segundos**. O contador de falhas e o tempo restante ficam salvos no armazenamento seguro, impedindo que o usuário burle a trava fechando e reabrindo o aplicativo.

---

## 🧠 Conceitos Abordados no Workshop

1. **O que a biometria é (e o que não é):** A biometria valida localmente a posse física do dispositivo para destrancar uma sessão ou chave já existente; ela **não substitui** a autenticação inicial em um servidor remoto.
2. **`flutter_secure_storage` vs. `shared_preferences`:**
   * `shared_preferences` grava pares chave-valor em arquivos XML/plist sem criptografia (texto puro), sendo inadequado para tokens, senhas ou chaves.
   * `flutter_secure_storage` utiliza o **Android Keystore** (com criptografia AES/RSA apoiada por hardware) e o **iOS Keychain**, garantindo que segredos fiquem protegidos mesmo em caso de acesso aos arquivos do app.
3. **Privacidade e Limitações (Android vs. iOS):**
   * O aplicativo **nunca tem acesso à imagem do rosto ou da impressão digital** do usuário; o sistema operacional processa a leitura em ambiente isolado (TEE / Secure Enclave) e retorna apenas um resultado booleano.
   * No Android, sensores faciais baseados apenas em câmera frontal 2D (*Class 1 - Convenience*) são bloqueados pelo próprio fabricante na API `BiometricPrompt` por serem vulneráveis a fotos, liberando apenas sensores fortes (*Class 3*, como leitor de digital ou Face ID 3D no iOS).

---

## 🛠️ Pacotes e Configurações Nativas

### Dependências (`pubspec.yaml`)
* [`local_auth`](https://pub.dev/packages/local_auth) — Comunicação com a API nativa de biometria e credenciais do dispositivo.
* [`flutter_secure_storage`](https://pub.dev/packages/flutter_secure_storage) — Armazenamento criptografado via Android Keystore / iOS Keychain.

### Ajustes Nativos no Android
* **`android/app/src/main/AndroidManifest.xml`:** Permissão `<uses-permission android:name="android.permission.USE_BIOMETRIC"/>` declarada dentro de `<manifest>` (acima de `<application>`).
* **`android/app/src/main/kotlin/.../MainActivity.kt`:** Classe principal herdando de `FlutterFragmentActivity()` (requisito obrigatório do `local_auth` para exibir o diálogo biométrico nativo).

---

## 📂 Estrutura do Código (`lib/`)

```text
lib/
├── main.dart                # Inicialização do app e configuração do tema Material 3
├── seguranca_service.dart   # Regras de biometria, fallback, bloqueio de 30s e Secure Storage
└── tela_cofre.dart          # Interface única com diagnóstico, bloqueio, Pix e troca de senha
```

---

## 🚀 Como Executar o Projeto

### Pré-requisitos
* [Flutter SDK](https://docs.flutter.dev/get-started/install) instalado e configurado.
* Um dispositivo Android/iOS físico ou emulador com bloqueio de tela/biometria configurado.

### Passo a passo

1. **Clone o repositório:**
   ```bash
   git clone <URL_DO_SEU_REPOSITORIO_GITHUB>
   cd <NOME_DA_PASTA_DO_PROJETO>
   ```

2. **Instale as dependências:**
   ```bash
   flutter pub get
   ```

3. **Execute o aplicativo:**
   ```bash
   flutter run
   ```

---

## 🧪 Roteiro Rápido de Testes

* **Senha padrão de fallback:** `1234` (pode ser alterada dentro da área desbloqueada pelo botão *Alterar Senha do App*).
* **Testando biometria no Emulador Android:**
  1. No emulador, acesse **Settings > Security & privacy > Device unlock > Fingerprint**.
  2. Configure um PIN de tela e inicie o cadastro de digital.
  3. Abra o menu lateral do emulador (`...`) > **Fingerprint**, selecione **Finger 1** e clique em **Touch the sensor** até concluir.
  4. No app, use **Finger 1** para autenticar com sucesso ou selecione **Finger 2** e toque 3 vezes no sensor para acionar o bloqueio de 30 segundos.