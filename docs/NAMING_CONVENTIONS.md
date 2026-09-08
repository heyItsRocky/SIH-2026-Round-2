# NAMING_CONVENTIONS

> Simple, consistent naming so the repository stays navigable with 6 contributors.

## Folders

- **Top-level areas** are numbered by lifecycle: `00_` (team/status), `01_`/`02_` (active projects), `03_` (shared tech), `04_` (archive), then `docs/`.
- **Project subfolders** are numbered by project lifecycle stage:
  - Idea 1: `PREVIOUS_ANALYSIS` (archived earlier-phase work, frozen) + `WORKSPACE` (squad's active area — organized freely by the squad)
  - Idea 2: `01_PROBLEM_INTELLIGENCE` → `02_DOMAIN_RESEARCH` → `03_ENVIRONMENTAL_ROBUSTNESS` → `04_SOLUTION_EXPLORATION` → `05_SYSTEM_ARCHITECTURE` → `06_PROTOTYPE` → `07_TESTING_VALIDATION` → `08_PRESENTATION`
- Use `UPPER_SNAKE_CASE` for numbered folders (`01_PROBLEM_UNDERSTANDING`).
- Use `Title_Case` for named folders (`Top_13_Ideas_Analysis`, `Rejected_Ideas`).
- **No spaces in folder names** (use `_`). Spaces break tooling and URLs.

## Files

- **Markdown docs:** `UPPER_SNAKE_CASE.md` for numbered/status docs (`00_CURRENT_STATUS.md`, `DECISION_001_PROJECT_SELECTION.md`); `Title_Case.md` for named docs (`ZERO_BUDGET_STRATEGY.md`).
- **Research files:** descriptive, topic-first — e.g., `thermal_management_papers.md`, `existing_solutions_gap_analysis.md`. Avoid `notes.md`, `final2.md`, `copy_of_...`.
- **Code files:** follow the language's own conventions (Python: `snake_case.py`; Arduino: `sketch.ino`).

## Decision Records

```text
DECISION_XXX_SHORT_DESCRIPTION.md
```

- `XXX` = sequential number (001, 002, ...).
- Short description in `UPPER_SNAKE_CASE` (e.g., `DECISION_002_IDEA2_APPROACH.md`).

## Meeting Notes

```text
MEETING_YYYY-MM-DD_TOPIC.md
```

Example: `MEETING_2026-09-08_Project_Selection.md`

## Rules of Thumb

1. **Descriptive beats clever.** A new member should understand a filename without opening it.
2. **No duplicates.** If a file with the same purpose exists, link to it instead of creating a copy.
3. **No spaces in paths.** Use `_` or `-`.
4. **Keep it consistent.** When in doubt, match the naming of the folder you're adding to.