# php2shell-target

Test target for the PHP "php2shell" RCE (CVE-2026-109619 / GHSA-6wmf-4rv5-p3rp).
The PHP engine is **8.2.34**, one release below the **8.2.35** fix, so it is in the
vulnerable range (`< 8.2.35 / 8.3.36 / 8.4.27 / 8.5.12`).

The engine is a language runtime, not a composer library, so no lockfile *installs*
it. A repo can still declare it in two ways, and the two show the version at a
different precision. This target carries both so you can compare them.

## Files

| File | Declares PHP as | Precision |
|------|-----------------|-----------|
| `composer.json` | `require.php: "^8.2"` (plus `config.platform.php: "8.2.34"`) | constraint (exact in config) |
| `composer.lock` | `platform.php: "^8.2"` (plus `platform-overrides.php: "8.2.34"`) | constraint (exact in override) |
| `sbom.cdx.json` | `cpe:2.3:a:php:php:8.2.34` | exact (built-image truth) |
| `sbom.syft.json` | `php-composer php 8.2.34` | exact |

`composer.lock` / `composer.json` are the **source** view: the manifest commits a
range (`^8.2`), so the real installed patch could be anywhere in `8.2.x`. The SBOM is
the **built-image** view: the exact resolved patch (`8.2.34`), with a CPE for matching.

The `composer.lock` here is hand-authored for testing, not from a real
`composer install` (the package `reference`/`shasum` are illustrative).

## How each view is detected

**Source view (composer files)** by `hybrid-sca-scanner`:

```sh
hybrid-sca-scanner . out.json
```

It reads the most precise declaration first: `composer.lock` `platform-overrides.php`,
then `composer.json` `config.platform.php` (both exact pins), then the constraint
fields `composer.lock` `platform.php` and `composer.json` `require.php`. An exact pin
yields a **high-confidence** finding; a constraint yields **low** (the installed patch
may already be fixed, since only the floor is known).

For this target the exact pin `8.2.34` in `platform-overrides` wins, so it reports
`php@8.2.34` at **high** confidence.

**Built-image view (SBOM)** by grype directly (reads cdx/spdx/syft JSON, no build):

```sh
grype sbom:sbom.cdx.json
```

This matches on the `cpe:2.3:a:php:php` identifier and reports the exact `8.2.34`.
Needs the CVE present in grype's DB.

Note: a `package-lock.json` would NOT help. That is the npm ecosystem; the PHP engine
is matched by CPE / OS-package / composer platform, not a JS lockfile.
