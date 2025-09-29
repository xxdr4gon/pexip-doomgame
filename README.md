# Pexip DOOM Plugin

A Pexip plugin that allows users to play DOOM during video conferences. Built with a custom DOOM port that runs entirely in the browser using WebAssembly.

## Features

- **Play DOOM**: Almost full gameplay experience in the browser (no network play :/)
- **No External Dependencies**: Self-contained with embedded DOOM game

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

If you need to rebuild the game from source:

1. **Obtain DOOM.WAD**: You must provide your own copy of DOOM.WAD (the original DOOM game data file) and place it in the `doom-source/` directory.

2. **Build the game**:
```bash
cd doom-source
wasm\node wasm\wajicup.js doom.c doom.html -embed DOOM.WAD DOOM.WAD -rle -template template.html
# Copy the generated doom.html to public/doom-crt.html
```

**Note**: DOOM.WAD is copyrighted material and is not included in this repository. You must obtain it separately from a legitimate source.

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
│   ├── DOOM.WAD         # Game data (user must provide)
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

## License

This project uses a custom DOOM port based on the original DOOM source code, which is licensed under the GNU General Public License 2.0.

## Credits

- Original DOOM by id Software
- DOOM port by Mattias Gustavsson
- The team behind Pexip Infinity
