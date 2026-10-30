# TODO - cockpit_vehicule

## Semaine 1 : le socle
- [x] dépôt, .gitignore, CMakeLists.txt, une fenêtre QML vide qui s'ouvre. Commit: `chore: project skeleton`
- [x] classe VehicleData avec speed, rpm, temperature en Q_PROPERTY (lecture, écriture, signal NOTIFY). Vérifie avec qDebug, sans QML. Commit: `feat: VehicleData properties`
- [x] expose la classe à QML et affiche la vitesse en texte. Commit: `feat: expose VehicleData to QML`
- [ ] un QTimer fait varier les valeurs de façon réaliste (accélération progressive, régime lié à la vitesse, température qui monte lentement). Commit: `feat: vehicle simulation`
- [ ] premier compteur visuel (aiguille ou arc) avec une animation (Behavior) pour que le mouvement soit fluide. Commit: `feat: speedometer`

## Semaine 2 : l'interface
- [ ] compose un composant Gauge.qml réutilisable (min, max, valeur), puis fais-en la jauge de régime. Commit: `refactor: reusable Gauge`
- [ ] voyants d'alerte (surchauffe, régime trop haut) pilotés par des seuils. Commit: `feat: warning lights`
- [ ] Theme.qml en singleton, thème jour/nuit commutable. Commit: `feat: day/night theme`
- [ ] modes Eco / Normal / Sport via une machine à états, qui changent seuils et couleurs. Commit: `feat: driving modes state machine`
- [ ] un effet de lueur sur une jauge avec ShaderEffect. Commit: `feat: gauge glow shader`

## Semaine 3 : la finition
- [ ] écran de réglages avec QSettings (thème, unités km/h ou mph, dernier mode). Commit: `feat: persistent settings`
- [ ] tests avec Qt Test et QSignalSpy (valeurs bornées, signaux émis). Commit: `test: VehicleData`
- [ ] README en anglais avec capture et GIF, puis tag v0.1. Commit: `docs: README and demo GIF`
- [ ] passe avec AddressSanitizer et clang-tidy, corrige ce qu'ils signalent.

## Notes
- Logique dans le C++, pas dans le QML
- Borne toujours tes valeurs
- Un commit par séance
- Écris d'abord, demande ensuite