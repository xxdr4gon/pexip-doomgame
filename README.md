# Pexip DOOM Plugin

A Pexip plugin that allows users to play and share DOOM gameplay during video conferences. Built with a custom DOOM port that runs entirely in the browser using WebAssembly.

## Features

- **Play DOOM**: Full DOOM gameplay experience in the browser
- **Share Gameplay**: Share your DOOM gameplay with other conference participants
- **Real-time Sharing**: Live canvas sharing with smooth 60fps gameplay
- **No External Dependencies**: Self-contained with embedded DOOM game

## How It Works

1. **Host starts playing**: Click the DOOM button to open the game in a panel
2. **Automatic sharing**: Gameplay is automatically shared to all participants
3. **Participants view**: Other participants see the gameplay in a floating overlay
4. **Stop sharing**: Close the game panel to stop sharing

## Technical Details

- Built using the Pexip Plugin API
- Custom DOOM port compiled to WebAssembly using WAjic
- Canvas-based sharing using `postMessage` communication
- Real-time frame sharing via Pexip's application message system

## Development

### Prerequisites

- Node.js 18+
- npm or yarn

### Setup

```bash
npm install
```

### Development

```bash
npm run dev
```

### Build

```bash
npm run build
```

### Preview

```bash
npm run preview
```

### Rebuilding DOOM

If you need to rebuild the DOOM game from source:

1. **Obtain DOOM1.WAD**: You must provide your own copy of DOOM1.WAD (the original DOOM game data file) and place it in the `doom-source/` directory.

2. **Build the game**:
```bash
cd doom-source
wasm\node wasm\wajicup.js doom.c doom.html -embed DOOM1.WAD DOOM1.WAD -rle -template template.html
# Copy the generated doom.html to public/doom-crt.html
```

**Note**: DOOM1.WAD is copyrighted material and is not included in this repository. You must obtain it separately from a legitimate source.

## Project Structure

```
├── src/
│   └── index.ts          # Main plugin logic
├── public/
│   ├── doom-crt.html     # Custom DOOM game (WebAssembly)
│   ├── icon.png          # Plugin icon
│   └── manifest.json     # Plugin manifest
├── doom-source/          # DOOM source code and build tools
│   ├── doom.c            # Main DOOM source
│   ├── DOOM1.WAD         # Game data (user must provide)
│   ├── linuxdoom-1.10/   # Original DOOM source
│   ├── libs_win32/       # Custom libraries
│   ├── wasm/             # WAjic build tools
│   └── template.html     # HTML template
├── dist/                 # Built plugin files
└── package.json
```

## Installation

1. Build the plugin: `npm run build`
2. Deploy the `dist/` folder to your Pexip environment
3. Configure the plugin in your Pexip admin interface

## License

This project uses a custom DOOM port based on the original DOOM source code, which is licensed under the GNU General Public License 2.0.

## Credits

- Original DOOM by id Software
- Custom DOOM port by Mattias Gustavsson
- Pexip Plugin API
